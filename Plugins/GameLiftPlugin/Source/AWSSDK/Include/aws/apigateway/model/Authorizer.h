﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/apigateway/APIGateway_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/apigateway/model/AuthorizerType.h>
#include <aws/core/utils/memory/stl/AWSVector.h>
#include <utility>

namespace Aws
{
namespace Utils
{
namespace Json
{
  class JsonValue;
  class JsonView;
} // namespace Json
} // namespace Utils
namespace APIGateway
{
namespace Model
{

  /**
   * <p>Represents an authorization layer for methods. If enabled on a method, API
   * Gateway will activate the authorizer when a client calls the
   * method.</p><p><h3>See Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/apigateway-2015-07-09/Authorizer">AWS
   * API Reference</a></p>
   */
  class Authorizer
  {
  public:
    AWS_APIGATEWAY_API Authorizer();
    AWS_APIGATEWAY_API Authorizer(Aws::Utils::Json::JsonView jsonValue);
    AWS_APIGATEWAY_API Authorizer& operator=(Aws::Utils::Json::JsonView jsonValue);
    AWS_APIGATEWAY_API Aws::Utils::Json::JsonValue Jsonize() const;


    ///@{
    /**
     * <p>The identifier for the authorizer resource.</p>
     */
    inline const Aws::String& GetId() const{ return m_id; }
    inline bool IdHasBeenSet() const { return m_idHasBeenSet; }
    inline void SetId(const Aws::String& value) { m_idHasBeenSet = true; m_id = value; }
    inline void SetId(Aws::String&& value) { m_idHasBeenSet = true; m_id = std::move(value); }
    inline void SetId(const char* value) { m_idHasBeenSet = true; m_id.assign(value); }
    inline Authorizer& WithId(const Aws::String& value) { SetId(value); return *this;}
    inline Authorizer& WithId(Aws::String&& value) { SetId(std::move(value)); return *this;}
    inline Authorizer& WithId(const char* value) { SetId(value); return *this;}
    ///@}

    ///@{
    /**
     * <p>The name of the authorizer.</p>
     */
    inline const Aws::String& GetName() const{ return m_name; }
    inline bool NameHasBeenSet() const { return m_nameHasBeenSet; }
    inline void SetName(const Aws::String& value) { m_nameHasBeenSet = true; m_name = value; }
    inline void SetName(Aws::String&& value) { m_nameHasBeenSet = true; m_name = std::move(value); }
    inline void SetName(const char* value) { m_nameHasBeenSet = true; m_name.assign(value); }
    inline Authorizer& WithName(const Aws::String& value) { SetName(value); return *this;}
    inline Authorizer& WithName(Aws::String&& value) { SetName(std::move(value)); return *this;}
    inline Authorizer& WithName(const char* value) { SetName(value); return *this;}
    ///@}

    ///@{
    /**
     * <p>The authorizer type. Valid values are <code>TOKEN</code> for a Lambda
     * function using a single authorization token submitted in a custom header,
     * <code>REQUEST</code> for a Lambda function using incoming request parameters,
     * and <code>COGNITO_USER_POOLS</code> for using an Amazon Cognito user pool.</p>
     */
    inline const AuthorizerType& GetType() const{ return m_type; }
    inline bool TypeHasBeenSet() const { return m_typeHasBeenSet; }
    inline void SetType(const AuthorizerType& value) { m_typeHasBeenSet = true; m_type = value; }
    inline void SetType(AuthorizerType&& value) { m_typeHasBeenSet = true; m_type = std::move(value); }
    inline Authorizer& WithType(const AuthorizerType& value) { SetType(value); return *this;}
    inline Authorizer& WithType(AuthorizerType&& value) { SetType(std::move(value)); return *this;}
    ///@}

    ///@{
    /**
     * <p>A list of the Amazon Cognito user pool ARNs for the
     * <code>COGNITO_USER_POOLS</code> authorizer. Each element is of this format:
     * <code>arn:aws:cognito-idp:{region}:{account_id}:userpool/{user_pool_id}</code>.
     * For a <code>TOKEN</code> or <code>REQUEST</code> authorizer, this is not
     * defined. </p>
     */
    inline const Aws::Vector<Aws::String>& GetProviderARNs() const{ return m_providerARNs; }
    inline bool ProviderARNsHasBeenSet() const { return m_providerARNsHasBeenSet; }
    inline void SetProviderARNs(const Aws::Vector<Aws::String>& value) { m_providerARNsHasBeenSet = true; m_providerARNs = value; }
    inline void SetProviderARNs(Aws::Vector<Aws::String>&& value) { m_providerARNsHasBeenSet = true; m_providerARNs = std::move(value); }
    inline Authorizer& WithProviderARNs(const Aws::Vector<Aws::String>& value) { SetProviderARNs(value); return *this;}
    inline Authorizer& WithProviderARNs(Aws::Vector<Aws::String>&& value) { SetProviderARNs(std::move(value)); return *this;}
    inline Authorizer& AddProviderARNs(const Aws::String& value) { m_providerARNsHasBeenSet = true; m_providerARNs.push_back(value); return *this; }
    inline Authorizer& AddProviderARNs(Aws::String&& value) { m_providerARNsHasBeenSet = true; m_providerARNs.push_back(std::move(value)); return *this; }
    inline Authorizer& AddProviderARNs(const char* value) { m_providerARNsHasBeenSet = true; m_providerARNs.push_back(value); return *this; }
    ///@}

    ///@{
    /**
     * <p>Optional customer-defined field, used in OpenAPI imports and exports without
     * functional impact.</p>
     */
    inline const Aws::String& GetAuthType() const{ return m_authType; }
    inline bool AuthTypeHasBeenSet() const { return m_authTypeHasBeenSet; }
    inline void SetAuthType(const Aws::String& value) { m_authTypeHasBeenSet = true; m_authType = value; }
    inline void SetAuthType(Aws::String&& value) { m_authTypeHasBeenSet = true; m_authType = std::move(value); }
    inline void SetAuthType(const char* value) { m_authTypeHasBeenSet = true; m_authType.assign(value); }
    inline Authorizer& WithAuthType(const Aws::String& value) { SetAuthType(value); return *this;}
    inline Authorizer& WithAuthType(Aws::String&& value) { SetAuthType(std::move(value)); return *this;}
    inline Authorizer& WithAuthType(const char* value) { SetAuthType(value); return *this;}
    ///@}

    ///@{
    /**
     * <p>Specifies the authorizer's Uniform Resource Identifier (URI). For
     * <code>TOKEN</code> or <code>REQUEST</code> authorizers, this must be a
     * well-formed Lambda function URI, for example,
     * <code>arn:aws:apigateway:us-west-2:lambda:path/2015-03-31/functions/arn:aws:lambda:us-west-2:{account_id}:function:{lambda_function_name}/invocations</code>.
     * In general, the URI has this form
     * <code>arn:aws:apigateway:{region}:lambda:path/{service_api}</code>, where
     * <code>{region}</code> is the same as the region hosting the Lambda function,
     * <code>path</code> indicates that the remaining substring in the URI should be
     * treated as the path to the resource, including the initial <code>/</code>. For
     * Lambda functions, this is usually of the form
     * <code>/2015-03-31/functions/[FunctionARN]/invocations</code>.</p>
     */
    inline const Aws::String& GetAuthorizerUri() const{ return m_authorizerUri; }
    inline bool AuthorizerUriHasBeenSet() const { return m_authorizerUriHasBeenSet; }
    inline void SetAuthorizerUri(const Aws::String& value) { m_authorizerUriHasBeenSet = true; m_authorizerUri = value; }
    inline void SetAuthorizerUri(Aws::String&& value) { m_authorizerUriHasBeenSet = true; m_authorizerUri = std::move(value); }
    inline void SetAuthorizerUri(const char* value) { m_authorizerUriHasBeenSet = true; m_authorizerUri.assign(value); }
    inline Authorizer& WithAuthorizerUri(const Aws::String& value) { SetAuthorizerUri(value); return *this;}
    inline Authorizer& WithAuthorizerUri(Aws::String&& value) { SetAuthorizerUri(std::move(value)); return *this;}
    inline Authorizer& WithAuthorizerUri(const char* value) { SetAuthorizerUri(value); return *this;}
    ///@}

    ///@{
    /**
     * <p>Specifies the required credentials as an IAM role for API Gateway to invoke
     * the authorizer. To specify an IAM role for API Gateway to assume, use the role's
     * Amazon Resource Name (ARN). To use resource-based permissions on the Lambda
     * function, specify null.</p>
     */
    inline const Aws::String& GetAuthorizerCredentials() const{ return m_authorizerCredentials; }
    inline bool AuthorizerCredentialsHasBeenSet() const { return m_authorizerCredentialsHasBeenSet; }
    inline void SetAuthorizerCredentials(const Aws::String& value) { m_authorizerCredentialsHasBeenSet = true; m_authorizerCredentials = value; }
    inline void SetAuthorizerCredentials(Aws::String&& value) { m_authorizerCredentialsHasBeenSet = true; m_authorizerCredentials = std::move(value); }
    inline void SetAuthorizerCredentials(const char* value) { m_authorizerCredentialsHasBeenSet = true; m_authorizerCredentials.assign(value); }
    inline Authorizer& WithAuthorizerCredentials(const Aws::String& value) { SetAuthorizerCredentials(value); return *this;}
    inline Authorizer& WithAuthorizerCredentials(Aws::String&& value) { SetAuthorizerCredentials(std::move(value)); return *this;}
    inline Authorizer& WithAuthorizerCredentials(const char* value) { SetAuthorizerCredentials(value); return *this;}
    ///@}

    ///@{
    /**
     * <p>The identity source for which authorization is requested. For a
     * <code>TOKEN</code> or <code>COGNITO_USER_POOLS</code> authorizer, this is
     * required and specifies the request header mapping expression for the custom
     * header holding the authorization token submitted by the client. For example, if
     * the token header name is <code>Auth</code>, the header mapping expression is
     * <code>method.request.header.Auth</code>. For the <code>REQUEST</code>
     * authorizer, this is required when authorization caching is enabled. The value is
     * a comma-separated string of one or more mapping expressions of the specified
     * request parameters. For example, if an <code>Auth</code> header, a
     * <code>Name</code> query string parameter are defined as identity sources, this
     * value is <code>method.request.header.Auth</code>,
     * <code>method.request.querystring.Name</code>. These parameters will be used to
     * derive the authorization caching key and to perform runtime validation of the
     * <code>REQUEST</code> authorizer by verifying all of the identity-related request
     * parameters are present, not null and non-empty. Only when this is true does the
     * authorizer invoke the authorizer Lambda function, otherwise, it returns a 401
     * Unauthorized response without calling the Lambda function. The valid value is a
     * string of comma-separated mapping expressions of the specified request
     * parameters. When the authorization caching is not enabled, this property is
     * optional. </p>
     */
    inline const Aws::String& GetIdentitySource() const{ return m_identitySource; }
    inline bool IdentitySourceHasBeenSet() const { return m_identitySourceHasBeenSet; }
    inline void SetIdentitySource(const Aws::String& value) { m_identitySourceHasBeenSet = true; m_identitySource = value; }
    inline void SetIdentitySource(Aws::String&& value) { m_identitySourceHasBeenSet = true; m_identitySource = std::move(value); }
    inline void SetIdentitySource(const char* value) { m_identitySourceHasBeenSet = true; m_identitySource.assign(value); }
    inline Authorizer& WithIdentitySource(const Aws::String& value) { SetIdentitySource(value); return *this;}
    inline Authorizer& WithIdentitySource(Aws::String&& value) { SetIdentitySource(std::move(value)); return *this;}
    inline Authorizer& WithIdentitySource(const char* value) { SetIdentitySource(value); return *this;}
    ///@}

    ///@{
    /**
     * <p>A validation expression for the incoming identity token. For
     * <code>TOKEN</code> authorizers, this value is a regular expression. For
     * <code>COGNITO_USER_POOLS</code> authorizers, API Gateway will match the
     * <code>aud</code> field of the incoming token from the client against the
     * specified regular expression. It will invoke the authorizer's Lambda function
     * when there is a match. Otherwise, it will return a 401 Unauthorized response
     * without calling the Lambda function. The validation expression does not apply to
     * the <code>REQUEST</code> authorizer.</p>
     */
    inline const Aws::String& GetIdentityValidationExpression() const{ return m_identityValidationExpression; }
    inline bool IdentityValidationExpressionHasBeenSet() const { return m_identityValidationExpressionHasBeenSet; }
    inline void SetIdentityValidationExpression(const Aws::String& value) { m_identityValidationExpressionHasBeenSet = true; m_identityValidationExpression = value; }
    inline void SetIdentityValidationExpression(Aws::String&& value) { m_identityValidationExpressionHasBeenSet = true; m_identityValidationExpression = std::move(value); }
    inline void SetIdentityValidationExpression(const char* value) { m_identityValidationExpressionHasBeenSet = true; m_identityValidationExpression.assign(value); }
    inline Authorizer& WithIdentityValidationExpression(const Aws::String& value) { SetIdentityValidationExpression(value); return *this;}
    inline Authorizer& WithIdentityValidationExpression(Aws::String&& value) { SetIdentityValidationExpression(std::move(value)); return *this;}
    inline Authorizer& WithIdentityValidationExpression(const char* value) { SetIdentityValidationExpression(value); return *this;}
    ///@}

    ///@{
    /**
     * <p>The TTL in seconds of cached authorizer results. If it equals 0,
     * authorization caching is disabled. If it is greater than 0, API Gateway will
     * cache authorizer responses. If this field is not set, the default value is 300.
     * The maximum value is 3600, or 1 hour.</p>
     */
    inline int GetAuthorizerResultTtlInSeconds() const{ return m_authorizerResultTtlInSeconds; }
    inline bool AuthorizerResultTtlInSecondsHasBeenSet() const { return m_authorizerResultTtlInSecondsHasBeenSet; }
    inline void SetAuthorizerResultTtlInSeconds(int value) { m_authorizerResultTtlInSecondsHasBeenSet = true; m_authorizerResultTtlInSeconds = value; }
    inline Authorizer& WithAuthorizerResultTtlInSeconds(int value) { SetAuthorizerResultTtlInSeconds(value); return *this;}
    ///@}

    ///@{
    
    inline const Aws::String& GetRequestId() const{ return m_requestId; }
    inline bool RequestIdHasBeenSet() const { return m_requestIdHasBeenSet; }
    inline void SetRequestId(const Aws::String& value) { m_requestIdHasBeenSet = true; m_requestId = value; }
    inline void SetRequestId(Aws::String&& value) { m_requestIdHasBeenSet = true; m_requestId = std::move(value); }
    inline void SetRequestId(const char* value) { m_requestIdHasBeenSet = true; m_requestId.assign(value); }
    inline Authorizer& WithRequestId(const Aws::String& value) { SetRequestId(value); return *this;}
    inline Authorizer& WithRequestId(Aws::String&& value) { SetRequestId(std::move(value)); return *this;}
    inline Authorizer& WithRequestId(const char* value) { SetRequestId(value); return *this;}
    ///@}
  private:

    Aws::String m_id;
    bool m_idHasBeenSet = false;

    Aws::String m_name;
    bool m_nameHasBeenSet = false;

    AuthorizerType m_type;
    bool m_typeHasBeenSet = false;

    Aws::Vector<Aws::String> m_providerARNs;
    bool m_providerARNsHasBeenSet = false;

    Aws::String m_authType;
    bool m_authTypeHasBeenSet = false;

    Aws::String m_authorizerUri;
    bool m_authorizerUriHasBeenSet = false;

    Aws::String m_authorizerCredentials;
    bool m_authorizerCredentialsHasBeenSet = false;

    Aws::String m_identitySource;
    bool m_identitySourceHasBeenSet = false;

    Aws::String m_identityValidationExpression;
    bool m_identityValidationExpressionHasBeenSet = false;

    int m_authorizerResultTtlInSeconds;
    bool m_authorizerResultTtlInSecondsHasBeenSet = false;

    Aws::String m_requestId;
    bool m_requestIdHasBeenSet = false;
  };

} // namespace Model
} // namespace APIGateway
} // namespace Aws
