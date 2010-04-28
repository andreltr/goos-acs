#ifndef irisCCDGUISaveDataToDisk_h
#define irisCCDGUISaveDataToDisk_h

/*
 * "@(#) $Id: irisCCDGUISaveDataToDisk.h,v 1.11  2009/12/04 10:37:25  mparra Exp $"
 *
 * $Log: irisCCDGUISaveDataToDisk.h,v $
 * Revision 1.11  2009/12/04 10:37:25  mparra
 * - Adapted to IRIS telescope name.
 * - Remove references to the Mount and Mirror components.
 *
 * Revision 1.10  2005/02/02 14:45:52  tjuerges
 * - Added functionality: displaying of every nth frame is possible.
 *
 * Revision 1.9  2004/12/28 17:31:12  tjuerges
 * - Added #ifdefs for developers not using the IRIS software. Say make -DNO_IRIS_USAGE to make the package compile without other iris ACS components.
 *
 * Revision 1.8  2004/12/28 13:43:21  tjuerges
 * - Changes needed due to strange bahaviour of SimpleClient. No two different connections to the same component from one SimpleCLient are possible.
 *
 * Revision 1.7  2004/11/25 17:52:19  tjuerges
 * - Added saving of MCU, M1 and M2 positions.
 *
 * Revision 1.6  2004/11/18 08:49:39  tjuerges
 * - myMonitor templates in irisStarUtils has been changed to use only two template parameters.
 *
 * Revision 1.5  2004/11/15 10:20:11  tjuerges
 * - ANpassungen an neues Monitor-Template.
 *
 * Revision 1.4  2004/11/02 13:20:19  tjuerges
 * - Datenpfad wird nicht mehr im Empf�nger gesetzt, sondern vom GUI selbst.
 *
 * Revision 1.1  2004/09/22 14:15:58  tjuerges
 * - F�r Simulation backgroundNoise und readoutNoise hinzugef�gt, rmsNoise entfernt.
 * - GUI speichert FITS auf Verlangen.
 * - GUI startet externes DS9 und beendet es.
 *
 *
 */

#include <qobject.h>
#include <qthread.h>
#include <qmutex.h>
#include <qstring.h>
#include <vector>
#include <string>
#include <irisStarUtils.h>
#include <acsutil.h>
#include <baciC.h>
#include <maciSimpleClient.h>
#include <irisCCDC.h>

#ifndef NO_IRIS_USAGE
#include <irisMntC.h>
#endif

ACE_RCSID(irisCCD,irisCCDGUISaveDataToDisk,"$Id: irisCCDGUISaveDataToDisk.h,v 1.11  2009/12/04 10:37:25  mparra Exp $");

class SaveDataToDisk: public QObject, QThread {
	//Qt Designer base class, Qt Designer object root tree and Qt Designer name.
Q_OBJECT

public:
	//Public function no uses for the Qt Designer signals.
	virtual ~SaveDataToDisk(void);
	virtual void run(void);
	virtual void image_arrived(void);
	virtual void setSimpleClient(maci::SimpleClient*);

public slots:
	//Qt Designer functions asociated whit a signal or action in the GUI.
	virtual void activate(bool);
	virtual void set_cameraName(const QString&);
	virtual void set_pathName(const QString&);
	virtual void delete_image(void);
	virtual void enable_save(bool);
	virtual void save_last(void);
	virtual void set_display_nth_frame(int);

	signals:
	//Qt Designer signal execute by the user in the GUI.
	void activate_saveToDisk(bool);
	void set_camera_name(const QString&);
	void set_path_name(const QString&);
	void clicked(void);
	void enable_saveToDisk(bool);
	void save_last_image(void);
	void valueChanged(int);

protected:

	virtual void connect(void);
	virtual void disconnect(void);
	virtual void connect_to_components(void);
	virtual void release_components(void);
	virtual void setup_property_values(void);
	virtual void destroy_properties(void);
	virtual void setup_monitor(void);
	virtual void destroy_monitor(void);
	virtual void display_file(const std::string&);

	bool saveImage;
	CORBA::Long last_img_width, last_img_height;
	std::vector<unsigned short int>* last_data;
	write_fits* last_image;

	maci::SimpleClient* mySimpleClient;myMonitor(long,SaveDataToDisk)* monitor;

	std::string pathname;
	std::string camera_name;
	std::string last_filename;
	//QMutex provides access serialization between threads, QMutex protect an object so that only one thread can access it at a time.
	QMutex display_nth_frame_mutex;
	int display_nth_frame;

	//We use synchronous method, this attribute is used for propagate information error.
	ACSErr::Completion_var completion;

	// Twice callback stuff. One for the monitor, one for the DO actions:
	ACS::CBlong_var callback;
	ACS::CBDescIn cb_desc;

#ifndef NO_IRIS_USAGE
	myComponentClient<irisMnt::Mnt>* client_Mnt;
	irisMnt::Mnt_var mount;
#endif

	// Read only properties of the camera DO:
	ACS::ROlongSeq_var img_sequence;
	ACS::ROdouble_var xPixelSize;
	ACS::ROdouble_var yPixelSize;
	ACS::ROdouble_var gain;
	ACS::ROdouble_var actualCCDTemperature;
	ACS::ROdouble_var actualAirTemperature;
	ACS::ROstring_var timeExposureStart;
	ACS::ROstring_var timeExposureEnd;
	ACS::ROdouble_var actualTemperature;

	// Writeable properties of the camera DO:
	ACS::RWlong_var xStart;
	ACS::RWlong_var xEnd;
	ACS::RWlong_var yStart;
	ACS::RWlong_var yEnd;
	ACS::RWlong_var darkFrame;
	ACS::RWdouble_var exposureTime;
	ACS::RWstring_var filterName;
	ACS::RWstring_var cameraName;
	ACS::RWstring_var telescopeName;
	ACS::RWdouble_var focalLength;
	ACS::RWstring_var observerName;
	ACS::RWstring_var objectName;
	ACS::RWdouble_var commandedCCDTemperature;
	ACS::RWlong_var exposureSequence;
	ACS::RWlong_var numberOfExposuresInSequence;
	ACS::RWdouble_var waitTimeBetweenExposuresInSequence;
	ACS::RWlong_var numberOfFlushes;

	/*
	 * Values received from the camera DO are put to these variables.
	 */

	std::vector<unsigned short int>* data;
	CORBA::Long max_width;
	CORBA::Long max_height;
	CORBA::Double focalLength_val;
	CORBA::Long img_width;
	CORBA::Long img_height;
	CORBA::Long darkFrame_val;
	CORBA::Double exposureTime_val;
	CORBA::String_var timeExposureStart_val;
	CORBA::String_var timeExposureEnd_val;
	CORBA::Double xPixelSize_val;
	CORBA::Double yPixelSize_val;
	CORBA::Double gain_val;
	CORBA::Double pixel_square;
	CORBA::String_var filterName_val;
	CORBA::String_var cameraName_val;
	CORBA::String_var telescopeName_val;
	CORBA::String_var observerName_val;
	CORBA::String_var objectName_val;
	CORBA::Double actualCCDTemperature_val;
	CORBA::Double actualAirTemperature_val;

#ifndef NO_IRIS_USAGE
	// Properties of the irisMount DO:
	ACS::RWdouble_var ra;
	ACS::RWdouble_var dec;
	ACS::RWdouble_var az;
	ACS::RWdouble_var ele;
	ACS::RWdouble_var pol;
	ACS::RWdouble_var ra_offset;
	ACS::RWdouble_var dec_offset;
	ACS::RWdouble_var az_offset;
	ACS::RWdouble_var ele_offset;
	ACS::RWdouble_var pol_offset;
	ACS::RWdouble_var equinox;

	/*
	 * Values received from the irisMount DO are put to these variables.
	 */

	CORBA::Double ra_val;
	CORBA::Double dec_val;
	CORBA::Double az_val;
	CORBA::Double ele_val;
	CORBA::Double pol_val;
	CORBA::Double ra_offset_val;
	CORBA::Double dec_offset_val;
	CORBA::Double az_offset_val;
	CORBA::Double ele_offset_val;
	CORBA::Double pol_offset_val;
	CORBA::Double equinox_val;
#endif
};

#endif //irisCCDGUISaveDataToDisk_h
