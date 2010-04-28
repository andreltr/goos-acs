/*
 * "@(#) $Id: irisCCDGUIEventLoop.h,v 1.2  2009/12/03 13:57:32  mparra Exp $"
 *
 * $Log: irisCCDGUIEventLoop.h,v $
 * Revision 1.2  2009/12/03 13:57:32  mparra
 * - Adapted to IRIS telescope name.
 *
 * Revision 1.1  2004/08/08 18:18:25  tjuerges
 * - irisCCDClient entschlackt.
 * - irisCCDGUI hinzujgef�gt.
 * - Aufr�umarbeiten in der Komponente.
 *
 *
 */

#ifndef IRISCCDGUIEVENTLOOP_H
#define IRISCCDGUIEVENTLOOP_H

#include <maciSimpleClient.h>
#include <qthread.h>

class eventLoop: public QThread
{
  public:
    virtual void run(void);
    virtual void setSimpleClient(maci::SimpleClient*);
    virtual void stop(void);

  private:
    maci::SimpleClient* sc;
    bool eventEnd;
};

#endif //IRISCCDGUIEVENTLOOP_H
