// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: token_request.proto

#ifndef PROTOBUF_INCLUDED_token_5frequest_2eproto
#define PROTOBUF_INCLUDED_token_5frequest_2eproto

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
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_token_5frequest_2eproto 

namespace protobuf_token_5frequest_2eproto {
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
}  // namespace protobuf_token_5frequest_2eproto
namespace sputnik {
namespace pb {
class DeleteTokenRequest;
class DeleteTokenRequestDefaultTypeInternal;
extern DeleteTokenRequestDefaultTypeInternal _DeleteTokenRequest_default_instance_;
class TokenActivation;
class TokenActivationDefaultTypeInternal;
extern TokenActivationDefaultTypeInternal _TokenActivation_default_instance_;
class TokenActivationRequest;
class TokenActivationRequestDefaultTypeInternal;
extern TokenActivationRequestDefaultTypeInternal _TokenActivationRequest_default_instance_;
}  // namespace pb
}  // namespace sputnik
namespace google {
namespace protobuf {
template<> ::sputnik::pb::DeleteTokenRequest* Arena::CreateMaybeMessage<::sputnik::pb::DeleteTokenRequest>(Arena*);
template<> ::sputnik::pb::TokenActivation* Arena::CreateMaybeMessage<::sputnik::pb::TokenActivation>(Arena*);
template<> ::sputnik::pb::TokenActivationRequest* Arena::CreateMaybeMessage<::sputnik::pb::TokenActivationRequest>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace sputnik {
namespace pb {

// ===================================================================

class TokenActivation : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:sputnik.pb.TokenActivation) */ {
 public:
  TokenActivation();
  virtual ~TokenActivation();

  TokenActivation(const TokenActivation& from);

  inline TokenActivation& operator=(const TokenActivation& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  TokenActivation(TokenActivation&& from) noexcept
    : TokenActivation() {
    *this = ::std::move(from);
  }

  inline TokenActivation& operator=(TokenActivation&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const TokenActivation& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const TokenActivation* internal_default_instance() {
    return reinterpret_cast<const TokenActivation*>(
               &_TokenActivation_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(TokenActivation* other);
  friend void swap(TokenActivation& a, TokenActivation& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline TokenActivation* New() const final {
    return CreateMaybeMessage<TokenActivation>(NULL);
  }

  TokenActivation* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<TokenActivation>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const TokenActivation& from);
  void MergeFrom(const TokenActivation& from);
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
  void InternalSwap(TokenActivation* other);
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

  // int32 token = 1;
  void clear_token();
  static const int kTokenFieldNumber = 1;
  ::google::protobuf::int32 token() const;
  void set_token(::google::protobuf::int32 value);

  // bool active = 2;
  void clear_active();
  static const int kActiveFieldNumber = 2;
  bool active() const;
  void set_active(bool value);

  // @@protoc_insertion_point(class_scope:sputnik.pb.TokenActivation)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::int32 token_;
  bool active_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_token_5frequest_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class TokenActivationRequest : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:sputnik.pb.TokenActivationRequest) */ {
 public:
  TokenActivationRequest();
  virtual ~TokenActivationRequest();

  TokenActivationRequest(const TokenActivationRequest& from);

  inline TokenActivationRequest& operator=(const TokenActivationRequest& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  TokenActivationRequest(TokenActivationRequest&& from) noexcept
    : TokenActivationRequest() {
    *this = ::std::move(from);
  }

  inline TokenActivationRequest& operator=(TokenActivationRequest&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const TokenActivationRequest& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const TokenActivationRequest* internal_default_instance() {
    return reinterpret_cast<const TokenActivationRequest*>(
               &_TokenActivationRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  void Swap(TokenActivationRequest* other);
  friend void swap(TokenActivationRequest& a, TokenActivationRequest& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline TokenActivationRequest* New() const final {
    return CreateMaybeMessage<TokenActivationRequest>(NULL);
  }

  TokenActivationRequest* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<TokenActivationRequest>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const TokenActivationRequest& from);
  void MergeFrom(const TokenActivationRequest& from);
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
  void InternalSwap(TokenActivationRequest* other);
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

  // repeated .sputnik.pb.TokenActivation token_activations = 1;
  int token_activations_size() const;
  void clear_token_activations();
  static const int kTokenActivationsFieldNumber = 1;
  ::sputnik::pb::TokenActivation* mutable_token_activations(int index);
  ::google::protobuf::RepeatedPtrField< ::sputnik::pb::TokenActivation >*
      mutable_token_activations();
  const ::sputnik::pb::TokenActivation& token_activations(int index) const;
  ::sputnik::pb::TokenActivation* add_token_activations();
  const ::google::protobuf::RepeatedPtrField< ::sputnik::pb::TokenActivation >&
      token_activations() const;

  // @@protoc_insertion_point(class_scope:sputnik.pb.TokenActivationRequest)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::sputnik::pb::TokenActivation > token_activations_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_token_5frequest_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class DeleteTokenRequest : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:sputnik.pb.DeleteTokenRequest) */ {
 public:
  DeleteTokenRequest();
  virtual ~DeleteTokenRequest();

  DeleteTokenRequest(const DeleteTokenRequest& from);

  inline DeleteTokenRequest& operator=(const DeleteTokenRequest& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  DeleteTokenRequest(DeleteTokenRequest&& from) noexcept
    : DeleteTokenRequest() {
    *this = ::std::move(from);
  }

  inline DeleteTokenRequest& operator=(DeleteTokenRequest&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const DeleteTokenRequest& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const DeleteTokenRequest* internal_default_instance() {
    return reinterpret_cast<const DeleteTokenRequest*>(
               &_DeleteTokenRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  void Swap(DeleteTokenRequest* other);
  friend void swap(DeleteTokenRequest& a, DeleteTokenRequest& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline DeleteTokenRequest* New() const final {
    return CreateMaybeMessage<DeleteTokenRequest>(NULL);
  }

  DeleteTokenRequest* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<DeleteTokenRequest>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const DeleteTokenRequest& from);
  void MergeFrom(const DeleteTokenRequest& from);
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
  void InternalSwap(DeleteTokenRequest* other);
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

  // repeated int32 delete_tokens = 1;
  int delete_tokens_size() const;
  void clear_delete_tokens();
  static const int kDeleteTokensFieldNumber = 1;
  ::google::protobuf::int32 delete_tokens(int index) const;
  void set_delete_tokens(int index, ::google::protobuf::int32 value);
  void add_delete_tokens(::google::protobuf::int32 value);
  const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
      delete_tokens() const;
  ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
      mutable_delete_tokens();

  // @@protoc_insertion_point(class_scope:sputnik.pb.DeleteTokenRequest)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedField< ::google::protobuf::int32 > delete_tokens_;
  mutable int _delete_tokens_cached_byte_size_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_token_5frequest_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// TokenActivation

// int32 token = 1;
inline void TokenActivation::clear_token() {
  token_ = 0;
}
inline ::google::protobuf::int32 TokenActivation::token() const {
  // @@protoc_insertion_point(field_get:sputnik.pb.TokenActivation.token)
  return token_;
}
inline void TokenActivation::set_token(::google::protobuf::int32 value) {
  
  token_ = value;
  // @@protoc_insertion_point(field_set:sputnik.pb.TokenActivation.token)
}

// bool active = 2;
inline void TokenActivation::clear_active() {
  active_ = false;
}
inline bool TokenActivation::active() const {
  // @@protoc_insertion_point(field_get:sputnik.pb.TokenActivation.active)
  return active_;
}
inline void TokenActivation::set_active(bool value) {
  
  active_ = value;
  // @@protoc_insertion_point(field_set:sputnik.pb.TokenActivation.active)
}

// -------------------------------------------------------------------

// TokenActivationRequest

// repeated .sputnik.pb.TokenActivation token_activations = 1;
inline int TokenActivationRequest::token_activations_size() const {
  return token_activations_.size();
}
inline void TokenActivationRequest::clear_token_activations() {
  token_activations_.Clear();
}
inline ::sputnik::pb::TokenActivation* TokenActivationRequest::mutable_token_activations(int index) {
  // @@protoc_insertion_point(field_mutable:sputnik.pb.TokenActivationRequest.token_activations)
  return token_activations_.Mutable(index);
}
inline ::google::protobuf::RepeatedPtrField< ::sputnik::pb::TokenActivation >*
TokenActivationRequest::mutable_token_activations() {
  // @@protoc_insertion_point(field_mutable_list:sputnik.pb.TokenActivationRequest.token_activations)
  return &token_activations_;
}
inline const ::sputnik::pb::TokenActivation& TokenActivationRequest::token_activations(int index) const {
  // @@protoc_insertion_point(field_get:sputnik.pb.TokenActivationRequest.token_activations)
  return token_activations_.Get(index);
}
inline ::sputnik::pb::TokenActivation* TokenActivationRequest::add_token_activations() {
  // @@protoc_insertion_point(field_add:sputnik.pb.TokenActivationRequest.token_activations)
  return token_activations_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::sputnik::pb::TokenActivation >&
TokenActivationRequest::token_activations() const {
  // @@protoc_insertion_point(field_list:sputnik.pb.TokenActivationRequest.token_activations)
  return token_activations_;
}

// -------------------------------------------------------------------

// DeleteTokenRequest

// repeated int32 delete_tokens = 1;
inline int DeleteTokenRequest::delete_tokens_size() const {
  return delete_tokens_.size();
}
inline void DeleteTokenRequest::clear_delete_tokens() {
  delete_tokens_.Clear();
}
inline ::google::protobuf::int32 DeleteTokenRequest::delete_tokens(int index) const {
  // @@protoc_insertion_point(field_get:sputnik.pb.DeleteTokenRequest.delete_tokens)
  return delete_tokens_.Get(index);
}
inline void DeleteTokenRequest::set_delete_tokens(int index, ::google::protobuf::int32 value) {
  delete_tokens_.Set(index, value);
  // @@protoc_insertion_point(field_set:sputnik.pb.DeleteTokenRequest.delete_tokens)
}
inline void DeleteTokenRequest::add_delete_tokens(::google::protobuf::int32 value) {
  delete_tokens_.Add(value);
  // @@protoc_insertion_point(field_add:sputnik.pb.DeleteTokenRequest.delete_tokens)
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
DeleteTokenRequest::delete_tokens() const {
  // @@protoc_insertion_point(field_list:sputnik.pb.DeleteTokenRequest.delete_tokens)
  return delete_tokens_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
DeleteTokenRequest::mutable_delete_tokens() {
  // @@protoc_insertion_point(field_mutable_list:sputnik.pb.DeleteTokenRequest.delete_tokens)
  return &delete_tokens_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace pb
}  // namespace sputnik

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_token_5frequest_2eproto
