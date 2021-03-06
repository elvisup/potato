// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: token_reply.proto

#ifndef PROTOBUF_INCLUDED_token_5freply_2eproto
#define PROTOBUF_INCLUDED_token_5freply_2eproto

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
#define PROTOBUF_INTERNAL_EXPORT_protobuf_token_5freply_2eproto 

namespace protobuf_token_5freply_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[2];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_token_5freply_2eproto
namespace sputnik {
namespace pb {
class DeleteTokenReply;
class DeleteTokenReplyDefaultTypeInternal;
extern DeleteTokenReplyDefaultTypeInternal _DeleteTokenReply_default_instance_;
class TokenActivationReply;
class TokenActivationReplyDefaultTypeInternal;
extern TokenActivationReplyDefaultTypeInternal _TokenActivationReply_default_instance_;
}  // namespace pb
}  // namespace sputnik
namespace google {
namespace protobuf {
template<> ::sputnik::pb::DeleteTokenReply* Arena::CreateMaybeMessage<::sputnik::pb::DeleteTokenReply>(Arena*);
template<> ::sputnik::pb::TokenActivationReply* Arena::CreateMaybeMessage<::sputnik::pb::TokenActivationReply>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace sputnik {
namespace pb {

enum TokenActivationReplyStatus {
  TAR_UNKNOWN = 0,
  TAR_SUCCESS = 1,
  TAR_FAILED = 2,
  TokenActivationReplyStatus_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  TokenActivationReplyStatus_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool TokenActivationReplyStatus_IsValid(int value);
const TokenActivationReplyStatus TokenActivationReplyStatus_MIN = TAR_UNKNOWN;
const TokenActivationReplyStatus TokenActivationReplyStatus_MAX = TAR_FAILED;
const int TokenActivationReplyStatus_ARRAYSIZE = TokenActivationReplyStatus_MAX + 1;

const ::google::protobuf::EnumDescriptor* TokenActivationReplyStatus_descriptor();
inline const ::std::string& TokenActivationReplyStatus_Name(TokenActivationReplyStatus value) {
  return ::google::protobuf::internal::NameOfEnum(
    TokenActivationReplyStatus_descriptor(), value);
}
inline bool TokenActivationReplyStatus_Parse(
    const ::std::string& name, TokenActivationReplyStatus* value) {
  return ::google::protobuf::internal::ParseNamedEnum<TokenActivationReplyStatus>(
    TokenActivationReplyStatus_descriptor(), name, value);
}
enum DeleteTokenReplyStatus {
  DFT_UNKNOWN = 0,
  DFT_SUCCESS = 1,
  DFT_FAILED = 2,
  DeleteTokenReplyStatus_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  DeleteTokenReplyStatus_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool DeleteTokenReplyStatus_IsValid(int value);
const DeleteTokenReplyStatus DeleteTokenReplyStatus_MIN = DFT_UNKNOWN;
const DeleteTokenReplyStatus DeleteTokenReplyStatus_MAX = DFT_FAILED;
const int DeleteTokenReplyStatus_ARRAYSIZE = DeleteTokenReplyStatus_MAX + 1;

const ::google::protobuf::EnumDescriptor* DeleteTokenReplyStatus_descriptor();
inline const ::std::string& DeleteTokenReplyStatus_Name(DeleteTokenReplyStatus value) {
  return ::google::protobuf::internal::NameOfEnum(
    DeleteTokenReplyStatus_descriptor(), value);
}
inline bool DeleteTokenReplyStatus_Parse(
    const ::std::string& name, DeleteTokenReplyStatus* value) {
  return ::google::protobuf::internal::ParseNamedEnum<DeleteTokenReplyStatus>(
    DeleteTokenReplyStatus_descriptor(), name, value);
}
// ===================================================================

class TokenActivationReply : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:sputnik.pb.TokenActivationReply) */ {
 public:
  TokenActivationReply();
  virtual ~TokenActivationReply();

  TokenActivationReply(const TokenActivationReply& from);

  inline TokenActivationReply& operator=(const TokenActivationReply& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  TokenActivationReply(TokenActivationReply&& from) noexcept
    : TokenActivationReply() {
    *this = ::std::move(from);
  }

  inline TokenActivationReply& operator=(TokenActivationReply&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const TokenActivationReply& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const TokenActivationReply* internal_default_instance() {
    return reinterpret_cast<const TokenActivationReply*>(
               &_TokenActivationReply_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(TokenActivationReply* other);
  friend void swap(TokenActivationReply& a, TokenActivationReply& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline TokenActivationReply* New() const final {
    return CreateMaybeMessage<TokenActivationReply>(NULL);
  }

  TokenActivationReply* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<TokenActivationReply>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const TokenActivationReply& from);
  void MergeFrom(const TokenActivationReply& from);
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
  void InternalSwap(TokenActivationReply* other);
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

  // repeated int32 active_tokens = 2;
  int active_tokens_size() const;
  void clear_active_tokens();
  static const int kActiveTokensFieldNumber = 2;
  ::google::protobuf::int32 active_tokens(int index) const;
  void set_active_tokens(int index, ::google::protobuf::int32 value);
  void add_active_tokens(::google::protobuf::int32 value);
  const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
      active_tokens() const;
  ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
      mutable_active_tokens();

  // .sputnik.pb.TokenActivationReplyStatus status = 1;
  void clear_status();
  static const int kStatusFieldNumber = 1;
  ::sputnik::pb::TokenActivationReplyStatus status() const;
  void set_status(::sputnik::pb::TokenActivationReplyStatus value);

  // @@protoc_insertion_point(class_scope:sputnik.pb.TokenActivationReply)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedField< ::google::protobuf::int32 > active_tokens_;
  mutable int _active_tokens_cached_byte_size_;
  int status_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_token_5freply_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class DeleteTokenReply : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:sputnik.pb.DeleteTokenReply) */ {
 public:
  DeleteTokenReply();
  virtual ~DeleteTokenReply();

  DeleteTokenReply(const DeleteTokenReply& from);

  inline DeleteTokenReply& operator=(const DeleteTokenReply& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  DeleteTokenReply(DeleteTokenReply&& from) noexcept
    : DeleteTokenReply() {
    *this = ::std::move(from);
  }

  inline DeleteTokenReply& operator=(DeleteTokenReply&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const DeleteTokenReply& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const DeleteTokenReply* internal_default_instance() {
    return reinterpret_cast<const DeleteTokenReply*>(
               &_DeleteTokenReply_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  void Swap(DeleteTokenReply* other);
  friend void swap(DeleteTokenReply& a, DeleteTokenReply& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline DeleteTokenReply* New() const final {
    return CreateMaybeMessage<DeleteTokenReply>(NULL);
  }

  DeleteTokenReply* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<DeleteTokenReply>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const DeleteTokenReply& from);
  void MergeFrom(const DeleteTokenReply& from);
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
  void InternalSwap(DeleteTokenReply* other);
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

  // repeated int32 present_tokens = 2;
  int present_tokens_size() const;
  void clear_present_tokens();
  static const int kPresentTokensFieldNumber = 2;
  ::google::protobuf::int32 present_tokens(int index) const;
  void set_present_tokens(int index, ::google::protobuf::int32 value);
  void add_present_tokens(::google::protobuf::int32 value);
  const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
      present_tokens() const;
  ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
      mutable_present_tokens();

  // .sputnik.pb.DeleteTokenReplyStatus status = 1;
  void clear_status();
  static const int kStatusFieldNumber = 1;
  ::sputnik::pb::DeleteTokenReplyStatus status() const;
  void set_status(::sputnik::pb::DeleteTokenReplyStatus value);

  // @@protoc_insertion_point(class_scope:sputnik.pb.DeleteTokenReply)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedField< ::google::protobuf::int32 > present_tokens_;
  mutable int _present_tokens_cached_byte_size_;
  int status_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_token_5freply_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// TokenActivationReply

// .sputnik.pb.TokenActivationReplyStatus status = 1;
inline void TokenActivationReply::clear_status() {
  status_ = 0;
}
inline ::sputnik::pb::TokenActivationReplyStatus TokenActivationReply::status() const {
  // @@protoc_insertion_point(field_get:sputnik.pb.TokenActivationReply.status)
  return static_cast< ::sputnik::pb::TokenActivationReplyStatus >(status_);
}
inline void TokenActivationReply::set_status(::sputnik::pb::TokenActivationReplyStatus value) {
  
  status_ = value;
  // @@protoc_insertion_point(field_set:sputnik.pb.TokenActivationReply.status)
}

// repeated int32 active_tokens = 2;
inline int TokenActivationReply::active_tokens_size() const {
  return active_tokens_.size();
}
inline void TokenActivationReply::clear_active_tokens() {
  active_tokens_.Clear();
}
inline ::google::protobuf::int32 TokenActivationReply::active_tokens(int index) const {
  // @@protoc_insertion_point(field_get:sputnik.pb.TokenActivationReply.active_tokens)
  return active_tokens_.Get(index);
}
inline void TokenActivationReply::set_active_tokens(int index, ::google::protobuf::int32 value) {
  active_tokens_.Set(index, value);
  // @@protoc_insertion_point(field_set:sputnik.pb.TokenActivationReply.active_tokens)
}
inline void TokenActivationReply::add_active_tokens(::google::protobuf::int32 value) {
  active_tokens_.Add(value);
  // @@protoc_insertion_point(field_add:sputnik.pb.TokenActivationReply.active_tokens)
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
TokenActivationReply::active_tokens() const {
  // @@protoc_insertion_point(field_list:sputnik.pb.TokenActivationReply.active_tokens)
  return active_tokens_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
TokenActivationReply::mutable_active_tokens() {
  // @@protoc_insertion_point(field_mutable_list:sputnik.pb.TokenActivationReply.active_tokens)
  return &active_tokens_;
}

// -------------------------------------------------------------------

// DeleteTokenReply

// .sputnik.pb.DeleteTokenReplyStatus status = 1;
inline void DeleteTokenReply::clear_status() {
  status_ = 0;
}
inline ::sputnik::pb::DeleteTokenReplyStatus DeleteTokenReply::status() const {
  // @@protoc_insertion_point(field_get:sputnik.pb.DeleteTokenReply.status)
  return static_cast< ::sputnik::pb::DeleteTokenReplyStatus >(status_);
}
inline void DeleteTokenReply::set_status(::sputnik::pb::DeleteTokenReplyStatus value) {
  
  status_ = value;
  // @@protoc_insertion_point(field_set:sputnik.pb.DeleteTokenReply.status)
}

// repeated int32 present_tokens = 2;
inline int DeleteTokenReply::present_tokens_size() const {
  return present_tokens_.size();
}
inline void DeleteTokenReply::clear_present_tokens() {
  present_tokens_.Clear();
}
inline ::google::protobuf::int32 DeleteTokenReply::present_tokens(int index) const {
  // @@protoc_insertion_point(field_get:sputnik.pb.DeleteTokenReply.present_tokens)
  return present_tokens_.Get(index);
}
inline void DeleteTokenReply::set_present_tokens(int index, ::google::protobuf::int32 value) {
  present_tokens_.Set(index, value);
  // @@protoc_insertion_point(field_set:sputnik.pb.DeleteTokenReply.present_tokens)
}
inline void DeleteTokenReply::add_present_tokens(::google::protobuf::int32 value) {
  present_tokens_.Add(value);
  // @@protoc_insertion_point(field_add:sputnik.pb.DeleteTokenReply.present_tokens)
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
DeleteTokenReply::present_tokens() const {
  // @@protoc_insertion_point(field_list:sputnik.pb.DeleteTokenReply.present_tokens)
  return present_tokens_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
DeleteTokenReply::mutable_present_tokens() {
  // @@protoc_insertion_point(field_mutable_list:sputnik.pb.DeleteTokenReply.present_tokens)
  return &present_tokens_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace pb
}  // namespace sputnik

namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::sputnik::pb::TokenActivationReplyStatus> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::sputnik::pb::TokenActivationReplyStatus>() {
  return ::sputnik::pb::TokenActivationReplyStatus_descriptor();
}
template <> struct is_proto_enum< ::sputnik::pb::DeleteTokenReplyStatus> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::sputnik::pb::DeleteTokenReplyStatus>() {
  return ::sputnik::pb::DeleteTokenReplyStatus_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_token_5freply_2eproto
