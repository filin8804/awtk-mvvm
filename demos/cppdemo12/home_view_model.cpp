﻿
/*This file is generated by code generator*/

#include "tkc/mem.h"
#include "tkc/utils.h"
#include "mvvm/base/utils.h"
#include "home_view_model.h"

static ret_t home_view_model_set_prop(object_t* obj, const char* name, const value_t* v) {
  Home* aHome = ((home_view_model_t*)(obj))->aHome;

  if (tk_str_ieq("bed_room_info", name)) {
    aHome->bed_room_info = value_str(v);

    return RET_OK;
  } else if (tk_str_ieq("living_room_info", name)) {
    aHome->living_room_info = value_str(v);

    return RET_OK;
  }

  return RET_NOT_FOUND;
}

static ret_t home_view_model_get_prop(object_t* obj, const char* name, value_t* v) {
  Home* aHome = ((home_view_model_t*)(obj))->aHome;

  if (tk_str_ieq("bed_room_info", name)) {
    value_set_str(v, aHome->bed_room_info.c_str());
    return RET_OK;
  } else if (tk_str_ieq("living_room_info", name)) {
    value_set_str(v, aHome->living_room_info.c_str());
    return RET_OK;
  }

  return RET_NOT_FOUND;
}

static bool_t home_view_model_can_exec(object_t* obj, const char* name, const char* args) {
  home_view_model_t* vm = (home_view_model_t*)(obj);
  Home* aHome = vm->aHome;
  if (tk_str_ieq("AdjustBedRoom", name)) {
    return TRUE;

  } else if (tk_str_ieq("AdjustLivingRoom", name)) {
    return TRUE;
  }
  return FALSE;
}

static ret_t home_view_model_exec(object_t* obj, const char* name, const char* args) {
  home_view_model_t* vm = (home_view_model_t*)(obj);
  Home* aHome = vm->aHome;
  if (tk_str_ieq("AdjustBedRoom", name)) {
    return aHome->AdjustBedRoom();

  } else if (tk_str_ieq("AdjustLivingRoom", name)) {
    return aHome->AdjustLivingRoom();
  }
  return RET_NOT_FOUND;
}

static ret_t home_view_model_on_destroy(object_t* obj) {
  home_view_model_t* vm = (home_view_model_t*)(obj);
  return_value_if_fail(vm != NULL, RET_BAD_PARAMS);

  emitter_off_by_ctx(EMITTER(vm->aHome), vm);
  delete (vm->aHome);

  return view_model_deinit(VIEW_MODEL(obj));
}

static const object_vtable_t s_home_view_model_vtable = {"home_view_model_t",
                                                         "home_view_model_t",
                                                         sizeof(home_view_model_t),
                                                         FALSE,
                                                         home_view_model_on_destroy,
                                                         NULL,
                                                         home_view_model_get_prop,
                                                         home_view_model_set_prop,
                                                         NULL,
                                                         NULL,
                                                         home_view_model_can_exec,
                                                         home_view_model_exec};

view_model_t* home_view_model_create_with(Home* aHome) {
  object_t* obj = object_create(&s_home_view_model_vtable);
  view_model_t* vm = view_model_init(VIEW_MODEL(obj));
  home_view_model_t* home_view_model = (home_view_model_t*)(vm);

  return_value_if_fail(vm != NULL, NULL);

  home_view_model->aHome = aHome;

  emitter_on(EMITTER(aHome), EVT_PROPS_CHANGED, emitter_forward, vm);
  emitter_on(EMITTER(aHome), EVT_ITEMS_CHANGED, emitter_forward, vm);

  return vm;
}

ret_t home_view_model_attach(view_model_t* vm, Home* aHome) {
  home_view_model_t* home_view_model = (home_view_model_t*)(vm);
  return_value_if_fail(vm != NULL, RET_BAD_PARAMS);

  home_view_model->aHome = aHome;

  return RET_OK;
}

view_model_t* home_view_model_create(navigator_request_t* req) {
  Home* aHome = new Home();
  return_value_if_fail(aHome != NULL, NULL);

  return home_view_model_create_with(aHome);
}