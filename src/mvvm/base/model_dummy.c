﻿/**
 * File:   model_dummy.c
 * Author: AWTK Develop Team
 * Brief:  model_dummy
 *
 * Copyright (c) 2019 - 2019  Guangzhou ZHIYUAN Electronics Co.,Ltd.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * License file for more details.
 *
 */

/**
 * History:
 * ================================================================
 * 2019-03-12 Li XianJing <xianjimli@hotmail.com> created
 *
 */

#include "tkc/utils.h"
#include "tkc/object_default.h"
#include "mvvm/base/model_dummy.h"

static ret_t model_dummy_on_destroy(object_t* obj) {
  model_dummy_t* dummy = MODEL_DUMMY(obj);

  object_unref(OBJECT(dummy->props));

  return RET_OK;
}

static int32_t model_dummy_compare(object_t* obj, object_t* other) {
  return tk_str_cmp(obj->name, other->name);
}

static ret_t model_dummy_set_prop(object_t* obj, const char* name, const value_t* v) {
  model_dummy_t* dummy = MODEL_DUMMY(obj);
  return_value_if_fail(obj != NULL && name != NULL && v != NULL, RET_BAD_PARAMS);

  return object_set_prop(OBJECT(dummy->props), name, v);
}

static ret_t model_dummy_get_prop(object_t* obj, const char* name, value_t* v) {
  model_dummy_t* dummy = MODEL_DUMMY(obj);
  return_value_if_fail(obj != NULL && name != NULL && v != NULL, RET_BAD_PARAMS);

  return object_get_prop(OBJECT(dummy->props), name, v);
}

static bool_t model_dummy_can_exec(object_t* obj, const char* name, const char* args) {
  model_dummy_t* dummy = MODEL_DUMMY(obj);
  return_value_if_fail(obj != NULL && name != NULL, FALSE);

  return TRUE;
}

static ret_t model_dummy_exec(object_t* obj, const char* name, const char* args) {
  model_dummy_t* dummy = MODEL_DUMMY(obj);
  return_value_if_fail(obj != NULL && name != NULL, RET_BAD_PARAMS);

  return RET_OK;
}

static const object_vtable_t s_model_dummy_vtable = {
    .type = "model_dummy",
    .desc = "model_dummy",
    .size = sizeof(model_dummy_t),
    .is_collection = FALSE,
    .on_destroy = model_dummy_on_destroy,

    .compare = model_dummy_compare,
    .get_prop = model_dummy_get_prop,
    .set_prop = model_dummy_set_prop,
    .can_exec = model_dummy_can_exec,
    .exec = model_dummy_exec};

model_t* model_dummy_create(navigator_request_t* req) {
  object_t* obj = object_create(&s_model_dummy_vtable);
  model_dummy_t* dummy = MODEL_DUMMY(obj);
  return_value_if_fail(dummy != NULL, NULL);

  dummy->props = object_default_create();

  return MODEL(obj);
}
