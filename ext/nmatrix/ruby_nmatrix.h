/////////////////////////////////////////////////////////////////////
// = NMatrix
//
// A linear algebra library for scientific computation in Ruby.
// NMatrix is part of SciRuby.
//
// NMatrix was originally inspired by and derived from NArray, by
// Masahiro Tanaka: http://narray.rubyforge.org
//
// == Copyright Information
//
// SciRuby is Copyright (c) 2010 - 2013, Ruby Science Foundation
// NMatrix is Copyright (c) 2013, Ruby Science Foundation
//
// Please see LICENSE.txt for additional copyright notices.
//
// == Contributing
//
// By contributing source code to SciRuby, you agree to be bound by
// our Contributor Agreement:
//
// * https://github.com/SciRuby/sciruby/wiki/Contributor-Agreement
//
// == ruby_nmatrix.h
//
// Internal header file for NMatrix

#ifndef RUBY_NMATRIX_H
#define RUBY_NMATRIX_H

#include "nmatrix.h"

#ifdef __cplusplus

extern "C" {
#endif

  // Non-API functions needed by other cpp files.
  _NMATRIX* nm_create(NM_DECL_ENUM(stype_t, stype), STORAGE* storage);
  _NMATRIX* nm_cast_with_ctype_args(NMATRIX* self, NM_DECL_ENUM(stype_t, new_stype), NM_DECL_ENUM(dtype_t, new_dtype), void* init_ptr);
  VALUE    nm_cast(VALUE self, VALUE new_stype_symbol, VALUE new_dtype_symbol, VALUE init);
  void     nm_mark(NMATRIX* mat);
  void     nm_delete(NMATRIX* mat);
  void     nm_delete_ref(NMATRIX* mat);
  void     nm_register_values(VALUE* vals, size_t n);
  void     nm_unregister_values(VALUE* vals, size_t n);
  void     nm_register_value(VALUE& val);
  void     nm_unregister_value(VALUE& val);
  void     nm_register_storage(nm::stype_t stype, const STORAGE* storage);
  void     nm_unregister_storage(nm::stype_t stype, const STORAGE* storage);
  void     nm_register_nmatrix(NMATRIX* nmatrix);
  void     nm_unregister_nmatrix(NMATRIX* nmatrix);
  void	   nm_completely_unregister_value(VALUE& val);
#ifdef __cplusplus
}
#endif

#endif // RUBY_NMATRIX_H
