// Filename: config_device.cxx
// Created by:  drose (04May00)
// 
////////////////////////////////////////////////////////////////////

#include "config_device.h"
#include "analogNode.h"
#include "buttonNode.h"
#include "clientAnalogDevice.h"
#include "clientBase.h"
#include "clientButtonDevice.h"
#include "clientDevice.h"
#include "clientTrackerDevice.h"
#include "mouse.h"
#include "trackerNode.h"

#include <dconfig.h>

Configure(config_device);
NotifyCategoryDef(device, "");

const bool asynchronous_clients = config_device.GetBool("asynchronous-clients", false);

ConfigureFn(config_device) {
  init_libdevice();
}

////////////////////////////////////////////////////////////////////
//     Function: init_libdevice
//  Description: Initializes the library.  This must be called at
//               least once before any of the functions or classes in
//               this library can be used.  Normally it will be
//               called by the static initializers and need not be
//               called explicitly, but special cases exist.
////////////////////////////////////////////////////////////////////
void
init_libdevice() {
  static bool initialized = false;
  if (initialized) {
    return;
  }
  initialized = true;

  AnalogNode::init_type();
  ButtonNode::init_type();
  ClientAnalogDevice::init_type();
  ClientBase::init_type();
  ClientButtonDevice::init_type();
  ClientDevice::init_type();
  ClientTrackerDevice::init_type();
  MouseAndKeyboard::init_type();
  TrackerNode::init_type();
}
