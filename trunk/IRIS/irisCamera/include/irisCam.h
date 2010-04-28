/*
 * "@(#) $Id: irisCam.h,v 1.1 2010/02/06 15:22:08 mparra Exp $"
 *
 * $Log: irisCam.h,v $
 * Revision 1.1 2010/02/06 15:22:08 mparra
 * - Adapted to IRIS telescope.
 */

#include "ace/OS.h"
#include "ace/OS_NS_stdio.h"
#include "ace/OS_NS_string.h"
#include "ace/OS_NS_unistd.h"
#include "ace/Log_Msg.h"
#include "ace/SOCK_Dgram.h"
#include "ace/INET_Addr.h"
#include "ace/SOCK_Acceptor.h"
#include "ace/SOCK_Stream.h"

#define DATA_BUFFER_SIZE 1024
#define SIZE_DATA 1024 

class irisClient
{

  public:

    irisClient(const char * remote_host_and_port) :
      remote_addr_(remote_host_and_port), local_addr_((u_short) 0), local_(local_addr_)
    {
      data_buf = new char[DATA_BUFFER_SIZE];
    }

    //Receive data from the remote host using the datgram wrapper `local_’.
    //The address of the remote machine is received in `remote_addr_’
    //which is of type ACE_INET_Addr. Remember that there is no established
    //connection.
    int accept_data()
    {
      char *p;
      if (local_.recv(data_buf, SIZE_DATA, remote_addr_) != -1)
      {
        p = strstr(data_buf, "OKAY ");
        if (p != NULL)
        {
          //ACS_SHORT_LOG((LM_INFO, ">>  %s\n", data_buf));
          return 1;
        };
      }
      else
        return -1;

      return 0;

    }

    //Send data to the remote. Once data has been sent wait for a reply
    //from the server.
    int quit()
    {
      //ACS_SHORT_LOG((LM_INFO,"Preparing to send data to server %s:%d\n",
      //	remote_addr_.get_host_name(),remote_addr_.get_port_number()));
      ACS_SHORT_LOG((LM_INFO, "Quit command send"));
      ACE_OS::sprintf(data_buf, "quit");
      for (int i = ACE_OS::strlen(data_buf); i < 1024; i++)
        data_buf[i] = '\0';
      while (local_.send(data_buf, DATA_BUFFER_SIZE, remote_addr_) != -1)
      {
        if (accept_data() == 1)
          break;
      }
      return -1;
    }

    int sync()
    {
      ACS_SHORT_LOG((LM_INFO, "Sync command send"));
      ACE_OS::sprintf(data_buf, "sync");
      for (int i = ACE_OS::strlen(data_buf); i < 1024; i++)
        data_buf[i] = '\0';
      while (local_.send(data_buf, DATA_BUFFER_SIZE, remote_addr_) != -1)
      {
        if (accept_data() == 1)
          break;
      }
      return -1;
    }

    int dl()
    {
      ACS_SHORT_LOG((LM_INFO, "Download command send"));
      ACE_OS::sprintf(data_buf, "dl");
      for (int i = ACE_OS::strlen(data_buf); i < 1024; i++)
        data_buf[i] = '\0';
      while (local_.send(data_buf, DATA_BUFFER_SIZE, remote_addr_) != -1)
      {
        if (accept_data() == 1)
          break;
      }
      return -1;
    }

    int go()
    {
      ACS_SHORT_LOG((LM_INFO, "Go command send"));
      ACE_OS::sprintf(data_buf, "go");
      for (int i = ACE_OS::strlen(data_buf); i < 1024; i++)
        data_buf[i] = '\0';
      while (local_.send(data_buf, DATA_BUFFER_SIZE, remote_addr_) != -1)
      {
        if (accept_data() == 1)
          break;
      }
      return -1;
    }

    int clear()
    {
      ACS_SHORT_LOG((LM_INFO, "Clear command send"));
      ACE_OS::sprintf(data_buf, "clear");
      for (int i = ACE_OS::strlen(data_buf); i < 1024; i++)
        data_buf[i] = '\0';
      while (local_.send(data_buf, DATA_BUFFER_SIZE, remote_addr_) != -1)
      {
        if (accept_data() == 1)
          break;
      }
      return -1;
    }

    int et(int seconds)
    {
      ACS_SHORT_LOG((LM_INFO, "Exposure time command send"));
      ACE_OS::sprintf(data_buf, "et %d", seconds);
      for (int i = ACE_OS::strlen(data_buf); i < 1024; i++)
        data_buf[i] = '\0';
      while (local_.send(data_buf, DATA_BUFFER_SIZE, remote_addr_) != -1)
      {
        if (accept_data() == 1)
          break;
      }
      return -1;
    }

    int xfer(char *host, char *port)
    {
      ACS_SHORT_LOG((LM_INFO, "Xfer command send"));
      ACE_OS::sprintf(data_buf, "xfer %s %s", host, port);
      for (int i = ACE_OS::strlen(data_buf); i < 1024; i++)
        data_buf[i] = '\0';
      while (local_.send(data_buf, DATA_BUFFER_SIZE, remote_addr_) != -1)
      {
        if (accept_data() == 1)
          break;
      }
      return -1;
    }

    int filter(char *position)
    {
      ACS_SHORT_LOG((LM_INFO, "filter command send"));
      ACE_OS::sprintf(data_buf, "filter %s", position);
      for (int i = ACE_OS::strlen(data_buf); i < 1024; i++)
        data_buf[i] = '\0';
      while (local_.send(data_buf, DATA_BUFFER_SIZE, remote_addr_) != -1)
      {
        if (accept_data() == 1)
          break;
      }
      return 0;
    }

  private:

    char *data_buf;
    ACE_INET_Addr remote_addr_;
    ACE_INET_Addr local_addr_;
    ACE_SOCK_Dgram local_;
};

class irisDataServer
{

  public:

    irisDataServer(int port) :
      server_addr_(port), peer_acceptor_(server_addr_)
    {
      data_buf_ = new char[DATA_BUFFER_SIZE];
      for (int i = 0; i < 1024; i++)
        for (int j = 0; j < 1024; j++)
          image_data_r[i][j] = image_data_d[i][j] = 0;

    }

    //Handle the connection once it has been established. Here the
    //connection is handled by reading SIZE_DATA amount of data from the
    //remote and then closing the connection stream down.
    int handle_connection()
    {
      // Read data from client
      int byte_count = 0;
      if ((byte_count = new_stream_.recv_n(data_buf_, 1024, 0)) == -1)
        ACE_ERROR((LM_ERROR, "%p\n", "Error in recv"));

      data_buf_[byte_count] = 0;
      ACS_SHORT_LOG(
          (LM_INFO, "Server received %d bytes %s %c", byte_count, data_buf_, data_buf_[22]));

      byte_count = 0;
      if (data_buf_[22] == 'r')
      {
        ACS_SHORT_LOG((LM_INFO, "r image detected"));
        if ((byte_count = new_stream_.recv_n(image_data_r, 1024 * 1024 * 2, 0)) == -1)
          ACE_ERROR((LM_ERROR, "%p\n", "Error in recv"));
      }
      else
      {
        ACS_SHORT_LOG((LM_INFO, "d image detected"));
        if ((byte_count = new_stream_.recv_n(image_data_d, 1024 * 1024 * 2, 0)) == -1)
          ACE_ERROR((LM_ERROR, "%p\n", "Error in recv"));
      }

      // Close new endpoint
      if (new_stream_.close() == -1)
        ACE_ERROR((LM_ERROR, "%p\n", "close"));
      return 0;
    }

    //Use the acceptor component peer_acceptor_ to accept the connection
    //into the underlying stream new_stream_. After the connection has been
    //established call the handle_connection() method.
    int accept_connections()
    {
      if (peer_acceptor_.get_local_addr(server_addr_) == -1)
        ACE_ERROR_RETURN((LM_ERROR, "%p\n", "irisDataServer: Error in get_local_addr"), 1);
      ACS_SHORT_LOG((LM_INFO, "Starting server at port %d", server_addr_.get_port_number()));
      // Performs the iterative server activities.
      ACE_Time_Value timeout(ACE_DEFAULT_TIMEOUT);
      acceptConn = true;

      while (acceptConn)
      {
        if (peer_acceptor_.accept(new_stream_, &client_addr_, &timeout) == -1)
        {
          //ACS_SHORT_LOG((LM_INFO, "accept: connection timed out, readerThreadRunning %d", acceptConn));
          continue;
        }
        else
        {
          ACS_SHORT_LOG(
              (LM_INFO, "Connection established with remote %s:%d", client_addr_.get_host_name(), client_addr_.get_port_number()));
          //Handle the connection
          handle_connection();
        }
      }
      // Close new endpoint
      if (new_stream_.close() == -1)
        ACE_ERROR((LM_ERROR, "%p\n", "close"));
      return 0;
    }

    int close_connections()
    {
      acceptConn = false;
      return 0;
    }

    int copy_data(unsigned short int tempImage[2048][1024])
    {
      for (int i = 0; i < 1024; i++)
        for (int j = 0; j < 1024; j++)
        {
          tempImage[i][j] = image_data_r[i][j];
          tempImage[i + 1024][j] = image_data_d[i][j];
        }
      return 0;
    }

    ~irisDataServer()
    {
      peer_acceptor_.close();
      close_connections();
      ACS_SHORT_LOG((LM_INFO, "Destroying irisDataServer object"));
    }

  private:

    char *data_buf_;
    ACE_INET_Addr server_addr_;
    ACE_INET_Addr client_addr_;
    ACE_SOCK_Acceptor peer_acceptor_;
    ACE_SOCK_Stream new_stream_;
    unsigned short int image_data_r[1024][1024];
    unsigned short int image_data_d[1024][1024];
    bool acceptConn;
};
