﻿
/*This file is generated by code generator*/

#include "tkc/mem.h"
#include "tkc/utils.h"
#include "mvvm/base/utils.h"
#include "book_view_model.h"

static ret_t book_view_model_set_prop(object_t* obj, const char* name, const value_t* v) {
  book_t* book = ((book_view_model_t*)(obj))->book;

  if (tk_str_eq("name", name)) {
     str_set(&(book->name), value_str(v));

     return RET_OK;
  } else if (tk_str_eq("stock", name)) {
     book->stock = value_uint32(v);

     return RET_OK;
  }
  
  return RET_NOT_FOUND;
}


static ret_t book_view_model_get_prop(object_t* obj, const char* name, value_t* v) {
  book_t* book = ((book_view_model_t*)(obj))->book;

  if (tk_str_eq("name", name)) {
     value_set_str(v, book->name.str);
     return RET_OK;
  } else if (tk_str_eq("stock", name)) {
     value_set_uint32(v, book->stock);
     return RET_OK;
  }

  return RET_NOT_FOUND;
}


static bool_t book_view_model_can_exec(object_t* obj, const char* name, const char* args) {
 
  book_view_model_t* vm = (book_view_model_t*)(obj);
  book_t* book = vm->book;
  if (tk_str_eq("sale", name)) {
    return book_can_sale(book);
  }
  return FALSE;
}

static ret_t book_view_model_exec(object_t* obj, const char* name, const char* args) {
 
  book_view_model_t* vm = (book_view_model_t*)(obj);
  book_t* book = vm->book;
  if (tk_str_eq("sale", name)) {
    return book_sale(book);
  }
  return RET_NOT_FOUND;
}

static ret_t book_view_model_on_destroy(object_t* obj) {
  book_view_model_t* vm = (book_view_model_t*)(obj);
  return_value_if_fail(vm != NULL, RET_BAD_PARAMS);

  
  book_destroy(vm->book);

  return view_model_deinit(VIEW_MODEL(obj));
}

static const object_vtable_t s_book_view_model_vtable = {
  .type = "book_view_model_t",
  .desc = "book_view_model_t",
  .size = sizeof(book_view_model_t),
  .exec = book_view_model_exec,
  .can_exec = book_view_model_can_exec,
  .get_prop = book_view_model_get_prop,
  .set_prop = book_view_model_set_prop,
  .on_destroy = book_view_model_on_destroy
};

view_model_t* book_view_model_create_with(book_t* book) {
  object_t* obj = object_create(&s_book_view_model_vtable);
  view_model_t* vm = view_model_init(VIEW_MODEL(obj));
  book_view_model_t* book_view_model = (book_view_model_t*)(vm);

  return_value_if_fail(vm != NULL, NULL);

  book_view_model->book = book;
  

  return vm;
}

ret_t book_view_model_attach(view_model_t* vm, book_t* book) {
  book_view_model_t* book_view_model = (book_view_model_t*)(vm);
  return_value_if_fail(vm != NULL, RET_BAD_PARAMS);

  book_view_model->book = book;

  return RET_OK;
}

view_model_t* book_view_model_create(navigator_request_t* req) {
  book_t* book = book_create();
  return_value_if_fail(book != NULL, NULL);

  return book_view_model_create_with(book);
}
