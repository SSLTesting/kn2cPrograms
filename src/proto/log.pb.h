// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: log.proto

#ifndef PROTOBUF_log_2eproto__INCLUDED
#define PROTOBUF_log_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3001000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3001000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include "vision_log.pb.h"
#include "ssl_log.pb.h"
#include "ref_log.pb.h"
// @@protoc_insertion_point(includes)
class Ref_chunk;
class Ref_chunkDefaultTypeInternal;
extern Ref_chunkDefaultTypeInternal _Ref_chunk_default_instance_;
class Ref_log;
class Ref_logDefaultTypeInternal;
extern Ref_logDefaultTypeInternal _Ref_log_default_instance_;
class SSL_log;
class SSL_logDefaultTypeInternal;
extern SSL_logDefaultTypeInternal _SSL_log_default_instance_;
class Vision_chunk;
class Vision_chunkDefaultTypeInternal;
extern Vision_chunkDefaultTypeInternal _Vision_chunk_default_instance_;
class Vision_log;
class Vision_logDefaultTypeInternal;
extern Vision_logDefaultTypeInternal _Vision_log_default_instance_;
class logRecord;
class logRecordDefaultTypeInternal;
extern logRecordDefaultTypeInternal _logRecord_default_instance_;
class log_chunk;
class log_chunkDefaultTypeInternal;
extern log_chunkDefaultTypeInternal _log_chunk_default_instance_;

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_log_2eproto();
void protobuf_InitDefaults_log_2eproto();

// ===================================================================

class logRecord : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:logRecord) */ {
 public:
  logRecord();
  virtual ~logRecord();

  logRecord(const logRecord& from);

  inline logRecord& operator=(const logRecord& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const logRecord& default_instance();

  static inline const logRecord* internal_default_instance() {
    return reinterpret_cast<const logRecord*>(
               &_logRecord_default_instance_);
  }

  void Swap(logRecord* other);

  // implements Message ----------------------------------------------

  inline logRecord* New() const PROTOBUF_FINAL { return New(NULL); }

  logRecord* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const logRecord& from);
  void MergeFrom(const logRecord& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output)
      const PROTOBUF_FINAL {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(logRecord* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional .SSL_log ai = 1;
  bool has_ai() const;
  void clear_ai();
  static const int kAiFieldNumber = 1;
  const ::SSL_log& ai() const;
  ::SSL_log* mutable_ai();
  ::SSL_log* release_ai();
  void set_allocated_ai(::SSL_log* ai);

  // optional .Vision_log vision = 2;
  bool has_vision() const;
  void clear_vision();
  static const int kVisionFieldNumber = 2;
  const ::Vision_log& vision() const;
  ::Vision_log* mutable_vision();
  ::Vision_log* release_vision();
  void set_allocated_vision(::Vision_log* vision);

  // optional .Ref_log referee = 3;
  bool has_referee() const;
  void clear_referee();
  static const int kRefereeFieldNumber = 3;
  const ::Ref_log& referee() const;
  ::Ref_log* mutable_referee();
  ::Ref_log* release_referee();
  void set_allocated_referee(::Ref_log* referee);

  // @@protoc_insertion_point(class_scope:logRecord)
 private:
  void set_has_ai();
  void clear_has_ai();
  void set_has_vision();
  void clear_has_vision();
  void set_has_referee();
  void clear_has_referee();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::SSL_log* ai_;
  ::Vision_log* vision_;
  ::Ref_log* referee_;
  friend void  protobuf_InitDefaults_log_2eproto_impl();
  friend void  protobuf_AddDesc_log_2eproto_impl();
  friend const ::google::protobuf::uint32* protobuf_Offsets_log_2eproto();
  friend void protobuf_ShutdownFile_log_2eproto();

};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// logRecord

// optional .SSL_log ai = 1;
inline bool logRecord::has_ai() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void logRecord::set_has_ai() {
  _has_bits_[0] |= 0x00000001u;
}
inline void logRecord::clear_has_ai() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void logRecord::clear_ai() {
  if (ai_ != NULL) ai_->::SSL_log::Clear();
  clear_has_ai();
}
inline const ::SSL_log& logRecord::ai() const {
  // @@protoc_insertion_point(field_get:logRecord.ai)
  return ai_ != NULL ? *ai_
                         : *::SSL_log::internal_default_instance();
}
inline ::SSL_log* logRecord::mutable_ai() {
  set_has_ai();
  if (ai_ == NULL) {
    ai_ = new ::SSL_log;
  }
  // @@protoc_insertion_point(field_mutable:logRecord.ai)
  return ai_;
}
inline ::SSL_log* logRecord::release_ai() {
  // @@protoc_insertion_point(field_release:logRecord.ai)
  clear_has_ai();
  ::SSL_log* temp = ai_;
  ai_ = NULL;
  return temp;
}
inline void logRecord::set_allocated_ai(::SSL_log* ai) {
  delete ai_;
  ai_ = ai;
  if (ai) {
    set_has_ai();
  } else {
    clear_has_ai();
  }
  // @@protoc_insertion_point(field_set_allocated:logRecord.ai)
}

// optional .Vision_log vision = 2;
inline bool logRecord::has_vision() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void logRecord::set_has_vision() {
  _has_bits_[0] |= 0x00000002u;
}
inline void logRecord::clear_has_vision() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void logRecord::clear_vision() {
  if (vision_ != NULL) vision_->::Vision_log::Clear();
  clear_has_vision();
}
inline const ::Vision_log& logRecord::vision() const {
  // @@protoc_insertion_point(field_get:logRecord.vision)
  return vision_ != NULL ? *vision_
                         : *::Vision_log::internal_default_instance();
}
inline ::Vision_log* logRecord::mutable_vision() {
  set_has_vision();
  if (vision_ == NULL) {
    vision_ = new ::Vision_log;
  }
  // @@protoc_insertion_point(field_mutable:logRecord.vision)
  return vision_;
}
inline ::Vision_log* logRecord::release_vision() {
  // @@protoc_insertion_point(field_release:logRecord.vision)
  clear_has_vision();
  ::Vision_log* temp = vision_;
  vision_ = NULL;
  return temp;
}
inline void logRecord::set_allocated_vision(::Vision_log* vision) {
  delete vision_;
  vision_ = vision;
  if (vision) {
    set_has_vision();
  } else {
    clear_has_vision();
  }
  // @@protoc_insertion_point(field_set_allocated:logRecord.vision)
}

// optional .Ref_log referee = 3;
inline bool logRecord::has_referee() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void logRecord::set_has_referee() {
  _has_bits_[0] |= 0x00000004u;
}
inline void logRecord::clear_has_referee() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void logRecord::clear_referee() {
  if (referee_ != NULL) referee_->::Ref_log::Clear();
  clear_has_referee();
}
inline const ::Ref_log& logRecord::referee() const {
  // @@protoc_insertion_point(field_get:logRecord.referee)
  return referee_ != NULL ? *referee_
                         : *::Ref_log::internal_default_instance();
}
inline ::Ref_log* logRecord::mutable_referee() {
  set_has_referee();
  if (referee_ == NULL) {
    referee_ = new ::Ref_log;
  }
  // @@protoc_insertion_point(field_mutable:logRecord.referee)
  return referee_;
}
inline ::Ref_log* logRecord::release_referee() {
  // @@protoc_insertion_point(field_release:logRecord.referee)
  clear_has_referee();
  ::Ref_log* temp = referee_;
  referee_ = NULL;
  return temp;
}
inline void logRecord::set_allocated_referee(::Ref_log* referee) {
  delete referee_;
  referee_ = referee;
  if (referee) {
    set_has_referee();
  } else {
    clear_has_referee();
  }
  // @@protoc_insertion_point(field_set_allocated:logRecord.referee)
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_log_2eproto__INCLUDED
