/*
 * "@(#) $Id: irisCCDGUIEventLoop.cpp,v 1.2 2009/12/03 14:45:24  mparra Exp $"
 *
 * $Log: irisCCDGUIEventLoop.cpp,v $
 * Revision 1.2  2009/12/03 14:45:24  mparra
 * - Adapted to IRIS telescope name.
 *
 * Revision 1.1  2004/08/08 18:18:25  tjuerges
 * - irisCCDClient entschlackt.
 * - irisCCDGUI hinzujgef�gt.
 * - Aufr�umarbeiten in der Komponente.
 *
 */

#include <irisCCDGUIEventLoop.h>
#include <maciSimpleClient.h>
#include <ace/Time_Value.h>

void eventLoop::setSimpleClient(maci::SimpleClient* theClient)
{
  sc = theClient;
}

void eventLoop::run(void)
{
  eventEnd = false;
  ACE_Time_Value t;

  while (!eventEnd)
  {
    t.set(5L, 0L);
    sc->run(t);
  }
}

void eventLoop::stop(void)
{
  eventEnd = true;
}
