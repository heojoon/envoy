#pragma once

#include <string>

#include "envoy/config/filter/network/client_ssl_auth/v2/client_ssl_auth.pb.h"
#include "envoy/server/filter_config.h"

#include "common/config/well_known_names.h"

namespace Envoy {
namespace Server {
namespace Configuration {

/**
 * Config registration for the client SSL auth filter. @see NamedNetworkFilterConfigFactory.
 */
class ClientSslAuthConfigFactory : public NamedNetworkFilterConfigFactory {
public:
  // NamedNetworkFilterConfigFactory
  NetworkFilterFactoryCb createFilterFactory(const Json::Object& json_config,
                                             FactoryContext& context) override;
  NetworkFilterFactoryCb createFilterFactoryFromProto(const Protobuf::Message& proto_config,
                                                      FactoryContext& context) override;

  ProtobufTypes::MessagePtr createEmptyConfigProto() override {
    return ProtobufTypes::MessagePtr{
        new envoy::config::filter::network::client_ssl_auth::v2::ClientSSLAuth()};
  }

  std::string name() override { return Config::NetworkFilterNames::get().CLIENT_SSL_AUTH; }

private:
  NetworkFilterFactoryCb createFilter(
      const envoy::config::filter::network::client_ssl_auth::v2::ClientSSLAuth& proto_config,
      FactoryContext& context);
};

} // namespace Configuration
} // namespace Server
} // namespace Envoy
