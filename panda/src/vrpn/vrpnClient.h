// Filename: vrpnClient.h
// Created by:  jason (04Aug00)
// 
////////////////////////////////////////////////////////////////////

#ifndef VRPNCLIENT_H
#define VRPNCLIENT_H

#include <pandabase.h>
#include <clientBase.h>

#include "vrpn_interface.h"

class VrpnTracker;
class VrpnTrackerDevice;
class VrpnButton;
class VrpnButtonDevice;
class VrpnAnalog;
class VrpnAnalogDevice;

////////////////////////////////////////////////////////////////////
//       Class : VrpnClient
// Description : A specific ClientBase that connects to a VRPN server
//               and records information on the connected VRPN
//               devices.
////////////////////////////////////////////////////////////////////
class EXPCL_PANDA VrpnClient : public ClientBase {
PUBLISHED:
  VrpnClient(const string &server_name);
  ~VrpnClient();

  INLINE const string &get_server_name() const;
  INLINE bool is_valid() const;
  INLINE bool is_connected() const;

  void write(ostream &out, int indent_level = 0) const;

public:
  INLINE static double convert_to_secs(struct timeval msg_time);
  
protected:
  virtual PT(ClientDevice) make_device(TypeHandle device_type,
				       const string &device_name);

  virtual bool disconnect_device(TypeHandle device_type, 
				 const string &device_name,
				 ClientDevice *device);

  virtual void do_poll();

private:
  PT(ClientDevice) make_tracker_device(const string &device_name);
  PT(ClientDevice) make_button_device(const string &device_name);
  PT(ClientDevice) make_analog_device(const string &device_name);
  void disconnect_tracker_device(VrpnTrackerDevice *device);
  void disconnect_button_device(VrpnButtonDevice *device);
  void disconnect_analog_device(VrpnAnalogDevice *device);

  VrpnTracker *get_tracker(const string &tracker_name);
  void free_tracker(VrpnTracker *vrpn_tracker);

  VrpnButton *get_button(const string &button_name);
  void free_button(VrpnButton *vrpn_button);

  VrpnAnalog *get_analog(const string &analog_name);
  void free_analog(VrpnAnalog *vrpn_analog);

private:
  string _server_name;
  vrpn_Connection *_connection;

  typedef map<string, VrpnTracker *> Trackers;
  typedef map<string, VrpnButton *> Buttons;
  typedef map<string, VrpnAnalog *> Analogs;

  Trackers _trackers;
  Buttons _buttons;
  Analogs _analogs;


public:
  static TypeHandle get_class_type() {
    return _type_handle;
  }
  static void init_type() {
    ClientBase::init_type();
    register_type(_type_handle, "VrpnClient",
                  ClientBase::get_class_type());
  }
  virtual TypeHandle get_type() const {
    return get_class_type();
  }
  virtual TypeHandle force_init_type() {init_type(); return get_class_type();}
 
private:
  static TypeHandle _type_handle;
};

#include "vrpnClient.I"

#endif


