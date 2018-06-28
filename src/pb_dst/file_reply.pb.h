// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: file_reply.proto

#ifndef PROTOBUF_INCLUDED_file_5freply_2eproto
#define PROTOBUF_INCLUDED_file_5freply_2eproto

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3005001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_file_5freply_2eproto 

namespace protobuf_file_5freply_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[3];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_file_5freply_2eproto
namespace sputnik {
namespace pb {
class FileReply;
class FileReplyDefaultTypeInternal;
extern FileReplyDefaultTypeInternal _FileReply_default_instance_;
class VerifyFileReply;
class VerifyFileReplyDefaultTypeInternal;
extern VerifyFileReplyDefaultTypeInternal _VerifyFileReply_default_instance_;
class WriteFileReply;
class WriteFileReplyDefaultTypeInternal;
extern WriteFileReplyDefaultTypeInternal _WriteFileReply_default_instance_;
}  // namespace pb
}  // namespace sputnik
namespace google {
namespace protobuf {
template<> ::sputnik::pb::FileReply* Arena::CreateMaybeMessage<::sputnik::pb::FileReply>(Arena*);
template<> ::sputnik::pb::VerifyFileReply* Arena::CreateMaybeMessage<::sputnik::pb::VerifyFileReply>(Arena*);
template<> ::sputnik::pb::WriteFileReply* Arena::CreateMaybeMessage<::sputnik::pb::WriteFileReply>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace sputnik {
namespace pb {

enum VerifyFileReplyStatus {
  VFRS_UNKNOWN = 0,
  VFRS_SUCCESS = 1,
  VFRS_MISMATCH = 2,
  VFRS_NO_FILE = 3,
  VerifyFileReplyStatus_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  VerifyFileReplyStatus_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool VerifyFileReplyStatus_IsValid(int value);
const VerifyFileReplyStatus VerifyFileReplyStatus_MIN = VFRS_UNKNOWN;
const VerifyFileReplyStatus VerifyFileReplyStatus_MAX = VFRS_NO_FILE;
const int VerifyFileReplyStatus_ARRAYSIZE = VerifyFileReplyStatus_MAX + 1;

const ::google::protobuf::EnumDescriptor* VerifyFileReplyStatus_descriptor();
inline const ::std::string& VerifyFileReplyStatus_Name(VerifyFileReplyStatus value) {
  return ::google::protobuf::internal::NameOfEnum(
    VerifyFileReplyStatus_descriptor(), value);
}
inline bool VerifyFileReplyStatus_Parse(
    const ::std::string& name, VerifyFileReplyStatus* value) {
  return ::google::protobuf::internal::ParseNamedEnum<VerifyFileReplyStatus>(
    VerifyFileReplyStatus_descriptor(), name, value);
}
enum WriteFileReplyStatus {
  WFRS_UNKNOWN = 0,
  WFRS_SUCCESS = 1,
  WFRS_NO_SPACE_LEFT = 2,
  WFRS_WRITE_FAILED = 3,
  WFRS_CANNOT_OVERWRITE = 4,
  WriteFileReplyStatus_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  WriteFileReplyStatus_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool WriteFileReplyStatus_IsValid(int value);
const WriteFileReplyStatus WriteFileReplyStatus_MIN = WFRS_UNKNOWN;
const WriteFileReplyStatus WriteFileReplyStatus_MAX = WFRS_CANNOT_OVERWRITE;
const int WriteFileReplyStatus_ARRAYSIZE = WriteFileReplyStatus_MAX + 1;

const ::google::protobuf::EnumDescriptor* WriteFileReplyStatus_descriptor();
inline const ::std::string& WriteFileReplyStatus_Name(WriteFileReplyStatus value) {
  return ::google::protobuf::internal::NameOfEnum(
    WriteFileReplyStatus_descriptor(), value);
}
inline bool WriteFileReplyStatus_Parse(
    const ::std::string& name, WriteFileReplyStatus* value) {
  return ::google::protobuf::internal::ParseNamedEnum<WriteFileReplyStatus>(
    WriteFileReplyStatus_descriptor(), name, value);
}
// ===================================================================

class VerifyFileReply : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:sputnik.pb.VerifyFileReply) */ {
 public:
  VerifyFileReply();
  virtual ~VerifyFileReply();

  VerifyFileReply(const VerifyFileReply& from);

  inline VerifyFileReply& operator=(const VerifyFileReply& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  VerifyFileReply(VerifyFileReply&& from) noexcept
    : VerifyFileReply() {
    *this = ::std::move(from);
  }

  inline VerifyFileReply& operator=(VerifyFileReply&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const VerifyFileReply& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const VerifyFileReply* internal_default_instance() {
    return reinterpret_cast<const VerifyFileReply*>(
               &_VerifyFileReply_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(VerifyFileReply* other);
  friend void swap(VerifyFileReply& a, VerifyFileReply& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline VerifyFileReply* New() const final {
    return CreateMaybeMessage<VerifyFileReply>(NULL);
  }

  VerifyFileReply* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<VerifyFileReply>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const VerifyFileReply& from);
  void MergeFrom(const VerifyFileReply& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(VerifyFileReply* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // .sputnik.pb.VerifyFileReplyStatus status = 1;
  void clear_status();
  static const int kStatusFieldNumber = 1;
  ::sputnik::pb::VerifyFileReplyStatus status() const;
  void set_status(::sputnik::pb::VerifyFileReplyStatus value);

  // @@protoc_insertion_point(class_scope:sputnik.pb.VerifyFileReply)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  int status_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_file_5freply_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class WriteFileReply : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:sputnik.pb.WriteFileReply) */ {
 public:
  WriteFileReply();
  virtual ~WriteFileReply();

  WriteFileReply(const WriteFileReply& from);

  inline WriteFileReply& operator=(const WriteFileReply& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  WriteFileReply(WriteFileReply&& from) noexcept
    : WriteFileReply() {
    *this = ::std::move(from);
  }

  inline WriteFileReply& operator=(WriteFileReply&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const WriteFileReply& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const WriteFileReply* internal_default_instance() {
    return reinterpret_cast<const WriteFileReply*>(
               &_WriteFileReply_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  void Swap(WriteFileReply* other);
  friend void swap(WriteFileReply& a, WriteFileReply& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline WriteFileReply* New() const final {
    return CreateMaybeMessage<WriteFileReply>(NULL);
  }

  WriteFileReply* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<WriteFileReply>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const WriteFileReply& from);
  void MergeFrom(const WriteFileReply& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(WriteFileReply* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // .sputnik.pb.WriteFileReplyStatus status = 1;
  void clear_status();
  static const int kStatusFieldNumber = 1;
  ::sputnik::pb::WriteFileReplyStatus status() const;
  void set_status(::sputnik::pb::WriteFileReplyStatus value);

  // @@protoc_insertion_point(class_scope:sputnik.pb.WriteFileReply)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  int status_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_file_5freply_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class FileReply : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:sputnik.pb.FileReply) */ {
 public:
  FileReply();
  virtual ~FileReply();

  FileReply(const FileReply& from);

  inline FileReply& operator=(const FileReply& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  FileReply(FileReply&& from) noexcept
    : FileReply() {
    *this = ::std::move(from);
  }

  inline FileReply& operator=(FileReply&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const FileReply& default_instance();

  enum ContentCase {
    kVerifyFileReply = 3,
    kWriteFileReply = 4,
    CONTENT_NOT_SET = 0,
  };

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const FileReply* internal_default_instance() {
    return reinterpret_cast<const FileReply*>(
               &_FileReply_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  void Swap(FileReply* other);
  friend void swap(FileReply& a, FileReply& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline FileReply* New() const final {
    return CreateMaybeMessage<FileReply>(NULL);
  }

  FileReply* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<FileReply>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const FileReply& from);
  void MergeFrom(const FileReply& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(FileReply* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string error_message = 2;
  void clear_error_message();
  static const int kErrorMessageFieldNumber = 2;
  const ::std::string& error_message() const;
  void set_error_message(const ::std::string& value);
  #if LANG_CXX11
  void set_error_message(::std::string&& value);
  #endif
  void set_error_message(const char* value);
  void set_error_message(const char* value, size_t size);
  ::std::string* mutable_error_message();
  ::std::string* release_error_message();
  void set_allocated_error_message(::std::string* error_message);

  // int32 request_id = 1;
  void clear_request_id();
  static const int kRequestIdFieldNumber = 1;
  ::google::protobuf::int32 request_id() const;
  void set_request_id(::google::protobuf::int32 value);

  // .sputnik.pb.VerifyFileReply verify_file_reply = 3;
  bool has_verify_file_reply() const;
  void clear_verify_file_reply();
  static const int kVerifyFileReplyFieldNumber = 3;
  private:
  const ::sputnik::pb::VerifyFileReply& _internal_verify_file_reply() const;
  public:
  const ::sputnik::pb::VerifyFileReply& verify_file_reply() const;
  ::sputnik::pb::VerifyFileReply* release_verify_file_reply();
  ::sputnik::pb::VerifyFileReply* mutable_verify_file_reply();
  void set_allocated_verify_file_reply(::sputnik::pb::VerifyFileReply* verify_file_reply);

  // .sputnik.pb.WriteFileReply write_file_reply = 4;
  bool has_write_file_reply() const;
  void clear_write_file_reply();
  static const int kWriteFileReplyFieldNumber = 4;
  private:
  const ::sputnik::pb::WriteFileReply& _internal_write_file_reply() const;
  public:
  const ::sputnik::pb::WriteFileReply& write_file_reply() const;
  ::sputnik::pb::WriteFileReply* release_write_file_reply();
  ::sputnik::pb::WriteFileReply* mutable_write_file_reply();
  void set_allocated_write_file_reply(::sputnik::pb::WriteFileReply* write_file_reply);

  void clear_content();
  ContentCase content_case() const;
  // @@protoc_insertion_point(class_scope:sputnik.pb.FileReply)
 private:
  void set_has_verify_file_reply();
  void set_has_write_file_reply();

  inline bool has_content() const;
  inline void clear_has_content();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr error_message_;
  ::google::protobuf::int32 request_id_;
  union ContentUnion {
    ContentUnion() {}
    ::sputnik::pb::VerifyFileReply* verify_file_reply_;
    ::sputnik::pb::WriteFileReply* write_file_reply_;
  } content_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  ::google::protobuf::uint32 _oneof_case_[1];

  friend struct ::protobuf_file_5freply_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// VerifyFileReply

// .sputnik.pb.VerifyFileReplyStatus status = 1;
inline void VerifyFileReply::clear_status() {
  status_ = 0;
}
inline ::sputnik::pb::VerifyFileReplyStatus VerifyFileReply::status() const {
  // @@protoc_insertion_point(field_get:sputnik.pb.VerifyFileReply.status)
  return static_cast< ::sputnik::pb::VerifyFileReplyStatus >(status_);
}
inline void VerifyFileReply::set_status(::sputnik::pb::VerifyFileReplyStatus value) {
  
  status_ = value;
  // @@protoc_insertion_point(field_set:sputnik.pb.VerifyFileReply.status)
}

// -------------------------------------------------------------------

// WriteFileReply

// .sputnik.pb.WriteFileReplyStatus status = 1;
inline void WriteFileReply::clear_status() {
  status_ = 0;
}
inline ::sputnik::pb::WriteFileReplyStatus WriteFileReply::status() const {
  // @@protoc_insertion_point(field_get:sputnik.pb.WriteFileReply.status)
  return static_cast< ::sputnik::pb::WriteFileReplyStatus >(status_);
}
inline void WriteFileReply::set_status(::sputnik::pb::WriteFileReplyStatus value) {
  
  status_ = value;
  // @@protoc_insertion_point(field_set:sputnik.pb.WriteFileReply.status)
}

// -------------------------------------------------------------------

// FileReply

// int32 request_id = 1;
inline void FileReply::clear_request_id() {
  request_id_ = 0;
}
inline ::google::protobuf::int32 FileReply::request_id() const {
  // @@protoc_insertion_point(field_get:sputnik.pb.FileReply.request_id)
  return request_id_;
}
inline void FileReply::set_request_id(::google::protobuf::int32 value) {
  
  request_id_ = value;
  // @@protoc_insertion_point(field_set:sputnik.pb.FileReply.request_id)
}

// string error_message = 2;
inline void FileReply::clear_error_message() {
  error_message_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& FileReply::error_message() const {
  // @@protoc_insertion_point(field_get:sputnik.pb.FileReply.error_message)
  return error_message_.GetNoArena();
}
inline void FileReply::set_error_message(const ::std::string& value) {
  
  error_message_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:sputnik.pb.FileReply.error_message)
}
#if LANG_CXX11
inline void FileReply::set_error_message(::std::string&& value) {
  
  error_message_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:sputnik.pb.FileReply.error_message)
}
#endif
inline void FileReply::set_error_message(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  error_message_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:sputnik.pb.FileReply.error_message)
}
inline void FileReply::set_error_message(const char* value, size_t size) {
  
  error_message_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:sputnik.pb.FileReply.error_message)
}
inline ::std::string* FileReply::mutable_error_message() {
  
  // @@protoc_insertion_point(field_mutable:sputnik.pb.FileReply.error_message)
  return error_message_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* FileReply::release_error_message() {
  // @@protoc_insertion_point(field_release:sputnik.pb.FileReply.error_message)
  
  return error_message_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void FileReply::set_allocated_error_message(::std::string* error_message) {
  if (error_message != NULL) {
    
  } else {
    
  }
  error_message_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), error_message);
  // @@protoc_insertion_point(field_set_allocated:sputnik.pb.FileReply.error_message)
}

// .sputnik.pb.VerifyFileReply verify_file_reply = 3;
inline bool FileReply::has_verify_file_reply() const {
  return content_case() == kVerifyFileReply;
}
inline void FileReply::set_has_verify_file_reply() {
  _oneof_case_[0] = kVerifyFileReply;
}
inline void FileReply::clear_verify_file_reply() {
  if (has_verify_file_reply()) {
    delete content_.verify_file_reply_;
    clear_has_content();
  }
}
inline const ::sputnik::pb::VerifyFileReply& FileReply::_internal_verify_file_reply() const {
  return *content_.verify_file_reply_;
}
inline ::sputnik::pb::VerifyFileReply* FileReply::release_verify_file_reply() {
  // @@protoc_insertion_point(field_release:sputnik.pb.FileReply.verify_file_reply)
  if (has_verify_file_reply()) {
    clear_has_content();
      ::sputnik::pb::VerifyFileReply* temp = content_.verify_file_reply_;
    content_.verify_file_reply_ = NULL;
    return temp;
  } else {
    return NULL;
  }
}
inline const ::sputnik::pb::VerifyFileReply& FileReply::verify_file_reply() const {
  // @@protoc_insertion_point(field_get:sputnik.pb.FileReply.verify_file_reply)
  return has_verify_file_reply()
      ? *content_.verify_file_reply_
      : *reinterpret_cast< ::sputnik::pb::VerifyFileReply*>(&::sputnik::pb::_VerifyFileReply_default_instance_);
}
inline ::sputnik::pb::VerifyFileReply* FileReply::mutable_verify_file_reply() {
  if (!has_verify_file_reply()) {
    clear_content();
    set_has_verify_file_reply();
    content_.verify_file_reply_ = CreateMaybeMessage< ::sputnik::pb::VerifyFileReply >(
        GetArenaNoVirtual());
  }
  // @@protoc_insertion_point(field_mutable:sputnik.pb.FileReply.verify_file_reply)
  return content_.verify_file_reply_;
}

// .sputnik.pb.WriteFileReply write_file_reply = 4;
inline bool FileReply::has_write_file_reply() const {
  return content_case() == kWriteFileReply;
}
inline void FileReply::set_has_write_file_reply() {
  _oneof_case_[0] = kWriteFileReply;
}
inline void FileReply::clear_write_file_reply() {
  if (has_write_file_reply()) {
    delete content_.write_file_reply_;
    clear_has_content();
  }
}
inline const ::sputnik::pb::WriteFileReply& FileReply::_internal_write_file_reply() const {
  return *content_.write_file_reply_;
}
inline ::sputnik::pb::WriteFileReply* FileReply::release_write_file_reply() {
  // @@protoc_insertion_point(field_release:sputnik.pb.FileReply.write_file_reply)
  if (has_write_file_reply()) {
    clear_has_content();
      ::sputnik::pb::WriteFileReply* temp = content_.write_file_reply_;
    content_.write_file_reply_ = NULL;
    return temp;
  } else {
    return NULL;
  }
}
inline const ::sputnik::pb::WriteFileReply& FileReply::write_file_reply() const {
  // @@protoc_insertion_point(field_get:sputnik.pb.FileReply.write_file_reply)
  return has_write_file_reply()
      ? *content_.write_file_reply_
      : *reinterpret_cast< ::sputnik::pb::WriteFileReply*>(&::sputnik::pb::_WriteFileReply_default_instance_);
}
inline ::sputnik::pb::WriteFileReply* FileReply::mutable_write_file_reply() {
  if (!has_write_file_reply()) {
    clear_content();
    set_has_write_file_reply();
    content_.write_file_reply_ = CreateMaybeMessage< ::sputnik::pb::WriteFileReply >(
        GetArenaNoVirtual());
  }
  // @@protoc_insertion_point(field_mutable:sputnik.pb.FileReply.write_file_reply)
  return content_.write_file_reply_;
}

inline bool FileReply::has_content() const {
  return content_case() != CONTENT_NOT_SET;
}
inline void FileReply::clear_has_content() {
  _oneof_case_[0] = CONTENT_NOT_SET;
}
inline FileReply::ContentCase FileReply::content_case() const {
  return FileReply::ContentCase(_oneof_case_[0]);
}
#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace pb
}  // namespace sputnik

namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::sputnik::pb::VerifyFileReplyStatus> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::sputnik::pb::VerifyFileReplyStatus>() {
  return ::sputnik::pb::VerifyFileReplyStatus_descriptor();
}
template <> struct is_proto_enum< ::sputnik::pb::WriteFileReplyStatus> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::sputnik::pb::WriteFileReplyStatus>() {
  return ::sputnik::pb::WriteFileReplyStatus_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_file_5freply_2eproto
