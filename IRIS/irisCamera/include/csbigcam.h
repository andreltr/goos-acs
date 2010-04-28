/*
 * "@(#) $Id: csbigcam.h,v 1.2  2010/02/07 13:36:21  mparra Exp $"
 *
 * $Log: csbigcam.h,v $
 * Revision 1.2  2010/02/07 13:36:21  mparra
 * - Add the method PAR_ERROR GetAirTemperature(double &airTemp) need by
 *   irisCameraSBIG class.
 * - Update the method QueryTemperatureStatus to work with the method GetAirTemperature.
 * - Add the method PAR_ERROR SetShutter(SHUTTER_COMMAND command) need by
 *   irisCameraSBIG class.
 * - Add the method PAR_ERROR SetMiscellaneousParams(MY_LOGICAL fan, SHUTTER_COMMAND shutter, LED_STATE led)
 *   require by the method SetShutter, also creates the attributes m_fanEnable and m_ledState.
 * - Add the method PAR_ERROR GetMiscellaneousParams(void) require by the method SetMiscellaneousParams,
 *   also added the attributes m_shutterState and m_shutterCommand.
 * - Add the method PAR_ERROR StartReadout(unsigned short top, unsigned short left, unsigned short height,
 unsigned short width) requiere by the irisCameraSBIG class.
 * - Add the method PAR_ERROR FastReadoutLine(ReadoutLineParams* rlp, unsigned short *dest) require by
 *   irisCameraSBIG class.
 * - Adapted the method double hex2double(unsigned long ul) require by irisCameraSBIG class.

 csbigcam.h - Contains the interface to the csbigcam
 camera class

 1. This software (c)2004-2006 Santa Barbara Instrument Group.
 2. This free software is provided as an example of how
 to communicate with SBIG cameras.  It is provided AS-IS
 without any guarantees by SBIG of suitability for a
 particular purpose and without any guarantee to be
 bug-free.  If you use it you agree to these terms and
 agree to do so at your own risk.
 3. Any distribution of this source code to include these
 terms.

 */

#ifndef _CSBIGCAM_
#define _CSBIGCAM_

#ifndef _PARDRV_
#include "sbigudrv.h"
#endif

#ifndef _CSBIGIMG_
#include "csbigimg.h"
#endif

#include <string>
using namespace std;

typedef enum
{
  RELAY_XPLUS, RELAY_XMINUS, RELAY_YPLUS, RELAY_YMINUS
} CAMERA_RELAY;
typedef enum
{
  SBDF_LIGHT_ONLY, SBDF_DARK_ONLY, SBDF_DARK_ALSO
} SBIG_DARK_FRAME;
typedef enum
{
  GS_IDLE,
  GS_DAWN,
  GS_EXPOSING_DARK,
  GS_DIGITIZING_DARK,
  GS_EXPOSING_LIGHT,
  GS_DIGITIZING_LIGHT,
  GS_DUSK
} GRAB_STATE;

class CSBIGCam
{
  private:
    PAR_ERROR m_eLastError;
    PAR_COMMAND m_eLastCommand;
    short m_nDrvHandle;
    CAMERA_TYPE m_eCameraType;
    CCD_REQUEST m_eActiveCCD;
    double m_dExposureTime;
    unsigned short m_uReadoutMode;
    ABG_STATE7 m_eABGState;
    int m_nSubFrameLeft, m_nSubFrameTop, m_nSubFrameWidth, m_nSubFrameHeight;
    GRAB_STATE m_eGrabState;
    double m_dGrabPercent;
    CFW_MODEL_SELECT m_eCFWModel;
    CFW_ERROR m_eCFWError;
    struct
    {
        unsigned short vertNBinning, hBin, vBin;
        unsigned short rm;
        int left, top, width, height;
    } m_sGrabInfo;

    //New attributes
    MY_LOGICAL m_fanEnable;
    LED_STATE m_ledState;
    SHUTTER_STATE7 m_shutterState;
    SHUTTER_COMMAND m_shutterCommand;

  public:
    // Constructors/Destructors
    CSBIGCam();
    CSBIGCam(OpenDeviceParams odp);
    CSBIGCam(SBIG_DEVICE_TYPE dev);
    ~CSBIGCam();
    void Init();

    // Error Reporting Routines
    PAR_ERROR GetError();
    string GetErrorString();
    string GetErrorString(PAR_ERROR err);
    PAR_COMMAND GetCommand();

    // Accessor Functions
    double GetExposureTime(void)
    {
      return m_dExposureTime;
    }
    void SetExposureTime(double exp)
    {
      m_dExposureTime = exp;
    }
    CCD_REQUEST GetActiveCCD(void)
    {
      return m_eActiveCCD;
    }
    void SetActiveCCD(CCD_REQUEST ccd)
    {
      m_eActiveCCD = ccd;
    }
    unsigned short GetReadoutMode(void)
    {
      return m_uReadoutMode;
    }
    void SetReadoutMode(unsigned short rm)
    {
      m_uReadoutMode = rm;
    }
    CAMERA_TYPE GetCameraType(void)
    {
      return m_eCameraType;
    }
    ABG_STATE7 GetABGState(void)
    {
      return m_eABGState;
    }
    void SetABGState(ABG_STATE7 abgState)
    {
      m_eABGState = abgState;
    }
    void SetSubFrame(int nLeft, int nTop, int nWidth, int nHeight);
    void GetSubFrame(int &nLeft, int &nTop, int &nWidth, int &nHeight);
    PAR_ERROR GetReadoutInfo(double &pixelWidth, double &pixelHeight, double &eGain);

    // Driver/Device Routines
    PAR_ERROR OpenDriver();
    PAR_ERROR CloseDriver();
    PAR_ERROR OpenDevice(OpenDeviceParams odp);
    PAR_ERROR CloseDevice();
    PAR_ERROR GetDriverInfo(DRIVER_REQUEST request, GetDriverInfoResults0 &gdir);

    // High-Level Exposure Related Commands
    PAR_ERROR GrabSetup(CSBIGImg *pImg, SBIG_DARK_FRAME dark);
    PAR_ERROR GrabMain(CSBIGImg *pImg, SBIG_DARK_FRAME dark);
    PAR_ERROR GrabImage(CSBIGImg *pImg, SBIG_DARK_FRAME dark);
    void GetGrabState(GRAB_STATE &grabState, double &percentComplete);

    // Low-Level Exposure Related Commands
    PAR_ERROR StartExposure(SHUTTER_COMMAND shutterState);
    PAR_ERROR EndExposure(void);
    PAR_ERROR IsExposureComplete(MY_LOGICAL &complete);
    PAR_ERROR StartReadout(StartReadoutParams srp);
    PAR_ERROR StartReadout(unsigned short top, unsigned short left, unsigned short height,
        unsigned short width);
    PAR_ERROR EndReadout(void);
    PAR_ERROR ReadoutLine(ReadoutLineParams rlp, MY_LOGICAL darkSubtract, unsigned short *dest);
    PAR_ERROR FastReadoutLine(ReadoutLineParams* rlp, unsigned short *dest);
    PAR_ERROR DumpLines(unsigned short noLines);

    //Temperature Related Commands
    PAR_ERROR GetCCDTemperature(double &ccdTemp);
    PAR_ERROR GetAirTemperature(double &airTemp);
    PAR_ERROR SetTemperatureRegulation(MY_LOGICAL enable, double setpoint);
    PAR_ERROR QueryTemperatureStatus(MY_LOGICAL &enabled, double &ccdTemp, double& airTemp,
        double &setpointTemp, double &percentTE);

    //Miscellaneous Commands
    PAR_ERROR SetShutter(SHUTTER_COMMAND command);
    PAR_ERROR SetMiscellaneousParams(MY_LOGICAL fan, SHUTTER_COMMAND shutter, LED_STATE led);
    PAR_ERROR GetMiscellaneousParams(void);

    // Control Related Commands
    PAR_ERROR ActivateRelay(CAMERA_RELAY relay, double time);
    PAR_ERROR IsRelayActive(CAMERA_RELAY relay, MY_LOGICAL &active);
    PAR_ERROR AOTipTilt(AOTipTiltParams attp);
    PAR_ERROR CFWCommand(CFWParams cfwp, CFWResults &cfwr);

    // General Purpose Commands
    PAR_ERROR EstablishLink(void);
    string GetCameraTypeString(void);
    PAR_ERROR GetFullFrame(int &nWidth, int &nHeight);
    PAR_ERROR GetFormattedCameraInfo(string &ciStr, MY_LOGICAL htmlFormat = TRUE);

    // Utility functions
    MY_LOGICAL CheckLink(void);
    unsigned short DegreesCToAD(double degC, MY_LOGICAL ccd = TRUE);
    double ADToDegreesC(unsigned short ad, MY_LOGICAL ccd = TRUE);

    //CFW Functions
    CFW_MODEL_SELECT GetCFWModel(void)
    {
      return m_eCFWModel;
    }
    PAR_ERROR SetCFWModel(CFW_MODEL_SELECT cfwModel, CFW_COM_PORT comPort = CFWPORT_COM1);
    PAR_ERROR SetCFWPosition(CFW_POSITION position);
    PAR_ERROR GetCFWPositionAndStatus(CFW_POSITION &position, CFW_STATUS &status);
    PAR_ERROR GetCFWMaxPosition(CFW_POSITION &position);
    CFW_ERROR GetCFWError(void)
    {
      return m_eCFWError;
    }
    string GetCFWErrorString(CFW_ERROR err);
    string GetCFWErrorString(void);

    double hex2double(unsigned long ul);

    // Allows access directly to driver
    PAR_ERROR SBIGUnivDrvCommand(short command, void *Params, void *Results);
};

#endif /* #ifndef _CSBIGCAM_ */
