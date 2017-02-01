// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: messages_robocup_ssl_refbox_log.proto

#ifndef PROTOBUF_messages_5frobocup_5fssl_5frefbox_5flog_2eproto__INCLUDED
#define PROTOBUF_messages_5frobocup_5fssl_5frefbox_5flog_2eproto__INCLUDED

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
#include "messages_robocup_ssl_detection.pb.h"
// @@protoc_insertion_point(includes)
class Log_Frame;
class Log_FrameDefaultTypeInternal;
extern Log_FrameDefaultTypeInternal _Log_Frame_default_instance_;
class Refbox_Log;
class Refbox_LogDefaultTypeInternal;
extern Refbox_LogDefaultTypeInternal _Refbox_Log_default_instance_;
class SSL_DetectionBall;
class SSL_DetectionBallDefaultTypeInternal;
extern SSL_DetectionBallDefaultTypeInternal _SSL_DetectionBall_default_instance_;
class SSL_DetectionFrame;
class SSL_DetectionFrameDefaultTypeInternal;
extern SSL_DetectionFrameDefaultTypeInternal _SSL_DetectionFrame_default_instance_;
class SSL_DetectionRobot;
class SSL_DetectionRobotDefaultTypeInternal;
extern SSL_DetectionRobotDefaultTypeInternal _SSL_DetectionRobot_default_instance_;

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_messages_5frobocup_5fssl_5frefbox_5flog_2eproto();
void protobuf_InitDefaults_messages_5frobocup_5fssl_5frefbox_5flog_2eproto();

// ===================================================================

class Log_Frame : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:Log_Frame) */ {
 public:
  Log_Frame();
  virtual ~Log_Frame();

  Log_Frame(const Log_Frame& from);

  inline Log_Frame& operator=(const Log_Frame& from) {
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
  static const Log_Frame& default_instance();

  static inline const Log_Frame* internal_default_instance() {
    return reinterpret_cast<const Log_Frame*>(
               &_Log_Frame_default_instance_);
  }

  void Swap(Log_Frame* other);

  // implements Message ----------------------------------------------

  inline Log_Frame* New() const PROTOBUF_FINAL { return New(NULL); }

  Log_Frame* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const Log_Frame& from);
  void MergeFrom(const Log_Frame& from);
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
  void InternalSwap(Log_Frame* other);
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

  // required .SSL_DetectionFrame frame = 1;
  bool has_frame() const;
  void clear_frame();
  static const int kFrameFieldNumber = 1;
  const ::SSL_DetectionFrame& frame() const;
  ::SSL_DetectionFrame* mutable_frame();
  ::SSL_DetectionFrame* release_frame();
  void set_allocated_frame(::SSL_DetectionFrame* frame);

  // required string refbox_cmd = 2;
  bool has_refbox_cmd() const;
  void clear_refbox_cmd();
  static const int kRefboxCmdFieldNumber = 2;
  const ::std::string& refbox_cmd() const;
  void set_refbox_cmd(const ::std::string& value);
  #if LANG_CXX11
  void set_refbox_cmd(::std::string&& value);
  #endif
  void set_refbox_cmd(const char* value);
  void set_refbox_cmd(const char* value, size_t size);
  ::std::string* mutable_refbox_cmd();
  ::std::string* release_refbox_cmd();
  void set_allocated_refbox_cmd(::std::string* refbox_cmd);

  // @@protoc_insertion_point(class_scope:Log_Frame)
 private:
  void set_has_frame();
  void clear_has_frame();
  void set_has_refbox_cmd();
  void clear_has_refbox_cmd();

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::internal::ArenaStringPtr refbox_cmd_;
  ::SSL_DetectionFrame* frame_;
  friend void  protobuf_InitDefaults_messages_5frobocup_5fssl_5frefbox_5flog_2eproto_impl();
  friend void  protobuf_AddDesc_messages_5frobocup_5fssl_5frefbox_5flog_2eproto_impl();
  friend const ::google::protobuf::uint32* protobuf_Offsets_messages_5frobocup_5fssl_5frefbox_5flog_2eproto();
  friend void protobuf_ShutdownFile_messages_5frobocup_5fssl_5frefbox_5flog_2eproto();

};
// -------------------------------------------------------------------

class Refbox_Log : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:Refbox_Log) */ {
 public:
  Refbox_Log();
  virtual ~Refbox_Log();

  Refbox_Log(const Refbox_Log& from);

  inline Refbox_Log& operator=(const Refbox_Log& from) {
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
  static const Refbox_Log& default_instance();

  static inline const Refbox_Log* internal_default_instance() {
    return reinterpret_cast<const Refbox_Log*>(
               &_Refbox_Log_default_instance_);
  }

  void Swap(Refbox_Log* other);

  // implements Message ----------------------------------------------

  inline Refbox_Log* New() const PROTOBUF_FINAL { return New(NULL); }

  Refbox_Log* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const Refbox_Log& from);
  void MergeFrom(const Refbox_Log& from);
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
  void InternalSwap(Refbox_Log* other);
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

  // repeated .Log_Frame log = 1;
  int log_size() const;
  void clear_log();
  static const int kLogFieldNumber = 1;
  const ::Log_Frame& log(int index) const;
  ::Log_Frame* mutable_log(int index);
  ::Log_Frame* add_log();
  ::google::protobuf::RepeatedPtrField< ::Log_Frame >*
      mutable_log();
  const ::google::protobuf::RepeatedPtrField< ::Log_Frame >&
      log() const;

  // @@protoc_insertion_point(class_scope:Refbox_Log)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::RepeatedPtrField< ::Log_Frame > log_;
  friend void  protobuf_InitDefaults_messages_5frobocup_5fssl_5frefbox_5flog_2eproto_impl();
  friend void  protobuf_AddDesc_messages_5frobocup_5fssl_5frefbox_5flog_2eproto_impl();
  friend const ::google::protobuf::uint32* protobuf_Offsets_messages_5frobocup_5fssl_5frefbox_5flog_2eproto();
  friend void protobuf_ShutdownFile_messages_5frobocup_5fssl_5frefbox_5flog_2eproto();

};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// Log_Frame

// required .SSL_DetectionFrame frame = 1;
inline bool Log_Frame::has_frame() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Log_Frame::set_has_frame() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Log_Frame::clear_has_frame() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Log_Frame::clear_frame() {
  if (frame_ != NULL) frame_->::SSL_DetectionFrame::Clear();
  clear_has_frame();
}
inline const ::SSL_DetectionFrame& Log_Frame::frame() const {
  // @@protoc_insertion_point(field_get:Log_Frame.frame)
  return frame_ != NULL ? *frame_
                         : *::SSL_DetectionFrame::internal_default_instance();
}
inline ::SSL_DetectionFrame* Log_Frame::mutable_frame() {
  set_has_frame();
  if (frame_ == NULL) {
    frame_ = new ::SSL_DetectionFrame;
  }
  // @@protoc_insertion_point(field_mutable:Log_Frame.frame)
  return frame_;
}
inline ::SSL_DetectionFrame* Log_Frame::release_frame() {
  // @@protoc_insertion_point(field_release:Log_Frame.frame)
  clear_has_frame();
  ::SSL_DetectionFrame* temp = frame_;
  frame_ = NULL;
  return temp;
}
inline void Log_Frame::set_allocated_frame(::SSL_DetectionFrame* frame) {
  delete frame_;
  frame_ = frame;
  if (frame) {
    set_has_frame();
  } else {
    clear_has_frame();
  }
  // @@protoc_insertion_point(field_set_allocated:Log_Frame.frame)
}

// required string refbox_cmd = 2;
inline bool Log_Frame::has_refbox_cmd() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Log_Frame::set_has_refbox_cmd() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Log_Frame::clear_has_refbox_cmd() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Log_Frame::clear_refbox_cmd() {
  refbox_cmd_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_refbox_cmd();
}
inline const ::std::string& Log_Frame::refbox_cmd() const {
  // @@protoc_insertion_point(field_get:Log_Frame.refbox_cmd)
  return refbox_cmd_.GetNoArena();
}
inline void Log_Frame::set_refbox_cmd(const ::std::string& value) {
  set_has_refbox_cmd();
  refbox_cmd_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:Log_Frame.refbox_cmd)
}
#if LANG_CXX11
inline void Log_Frame::set_refbox_cmd(::std::string&& value) {
  set_has_refbox_cmd();
  refbox_cmd_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:Log_Frame.refbox_cmd)
}
#endif
inline void Log_Frame::set_refbox_cmd(const char* value) {
  set_has_refbox_cmd();
  refbox_cmd_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:Log_Frame.refbox_cmd)
}
inline void Log_Frame::set_refbox_cmd(const char* value, size_t size) {
  set_has_refbox_cmd();
  refbox_cmd_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:Log_Frame.refbox_cmd)
}
inline ::std::string* Log_Frame::mutable_refbox_cmd() {
  set_has_refbox_cmd();
  // @@protoc_insertion_point(field_mutable:Log_Frame.refbox_cmd)
  return refbox_cmd_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Log_Frame::release_refbox_cmd() {
  // @@protoc_insertion_point(field_release:Log_Frame.refbox_cmd)
  clear_has_refbox_cmd();
  return refbox_cmd_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Log_Frame::set_allocated_refbox_cmd(::std::string* refbox_cmd) {
  if (refbox_cmd != NULL) {
    set_has_refbox_cmd();
  } else {
    clear_has_refbox_cmd();
  }
  refbox_cmd_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), refbox_cmd);
  // @@protoc_insertion_point(field_set_allocated:Log_Frame.refbox_cmd)
}

// -------------------------------------------------------------------

// Refbox_Log

// repeated .Log_Frame log = 1;
inline int Refbox_Log::log_size() const {
  return log_.size();
}
inline void Refbox_Log::clear_log() {
  log_.Clear();
}
inline const ::Log_Frame& Refbox_Log::log(int index) const {
  // @@protoc_insertion_point(field_get:Refbox_Log.log)
  return log_.Get(index);
}
inline ::Log_Frame* Refbox_Log::mutable_log(int index) {
  // @@protoc_insertion_point(field_mutable:Refbox_Log.log)
  return log_.Mutable(index);
}
inline ::Log_Frame* Refbox_Log::add_log() {
  // @@protoc_insertion_point(field_add:Refbox_Log.log)
  return log_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::Log_Frame >*
Refbox_Log::mutable_log() {
  // @@protoc_insertion_point(field_mutable_list:Refbox_Log.log)
  return &log_;
}
inline const ::google::protobuf::RepeatedPtrField< ::Log_Frame >&
Refbox_Log::log() const {
  // @@protoc_insertion_point(field_list:Refbox_Log.log)
  return log_;
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_messages_5frobocup_5fssl_5frefbox_5flog_2eproto__INCLUDED
