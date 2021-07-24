/*
 * FreeRTOS V202107.00
 * Copyright (C) 2020 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * https://www.FreeRTOS.org
 * https://github.com/FreeRTOS
 *
 */

#ifndef DEMO_CONFIG_H
#define DEMO_CONFIG_H

/**************************************************/
/******* DO NOT CHANGE the following order ********/
/**************************************************/

/* Include logging header files and define logging macros in the following order:
 * 1. Include the header file "logging_levels.h".
 * 2. Define the LIBRARY_LOG_NAME and LIBRARY_LOG_LEVEL macros depending on
 * the logging configuration for DEMO.
 * 3. Include the header file "logging_stack.h", if logging is enabled for DEMO.
 */

/* Include header that defines log levels. */
#include "logging_levels.h"

/* Logging configuration for the demo. */
#ifndef LIBRARY_LOG_NAME
    #define LIBRARY_LOG_NAME    "HTTPDemo"
#endif

#ifndef LIBRARY_LOG_LEVEL
    #define LIBRARY_LOG_LEVEL    LOG_INFO
#endif

/* Prototype for the function used to print to console on Windows simulator
 * of FreeRTOS.
 * The function prints to the console before the network is connected;
 * then a UDP port after the network has connected. */
extern void vLoggingPrintf( const char * pcFormatString,
                            ... );

/* Map the SdkLog macro to the logging function to enable logging
 * on Windows simulator. */
#ifndef SdkLog
    #define SdkLog( message )    vLoggingPrintf message
#endif

#include "logging_stack.h"

/************ End of logging configuration ****************/

/**
 * @brief HTTP server port number.
 *
 * For this demo, an X.509 certificate is used to verify the client.
 */
#ifndef democonfigHTTPS_PORT
    #define democonfigHTTPS_PORT    443
#endif

/**
 * @brief Server's root CA certificate for TLS authentication with S3.
 *
 * The Baltimore Cybertrust root CA certificate is often used for authentication
 * with S3. It can be found at:
 * https://baltimore-cybertrust-root.chain-demos.digicert.com/info/index.html.
 *
 * S3 has started migrating certificates to Amazon Trust Services. If
 * authentication errors persist, re-attempt the connection with an Amazon root
 * CA certificate: https://www.amazontrust.com/repository.
 *
 * @note This certificate should be PEM-encoded.
 *
 * Must include the PEM header and footer:
 * "-----BEGIN CERTIFICATE-----\n"\
 * "...base64 data...\n"\
 * "-----END CERTIFICATE-----\n"
 *
 * #define democonfigROOT_CA_PEM    "...insert here..."
 */

/**
 * @brief The pre-signed GET URL generated by the python script located in
 * FreeRTOS-Plus\Demo\coreHTTP_Windows_Simulator\Common\presigned_url_generator\presigned_urls_gen.py
 *
 * @note This script requires AWS CLI to be configured. For instructions, see
 * https://docs.aws.amazon.com/cli/latest/userguide/cli-chap-configure.html
 *
 * Run this script and paste the output democonfigS3_PRESIGNED_GET_URL below.
 *
 * #define democonfigS3_PRESIGNED_GET_URL         "...insert here..."
 */

/**
 * @brief The pre-signed PUT URL generated by the python script located in
 * FreeRTOS-Plus\Demo\coreHTTP_Windows_Simulator\Common\presigned_url_generator\presigned_urls_gen.py
 *
 * @note This script requires AWS CLI to be configured. For instructions, see
 * https://docs.aws.amazon.com/cli/latest/userguide/cli-chap-configure.html
 *
 * Run this script and paste the output democonfigS3_PRESIGNED_PUT_URL below.
 *
 * #define democonfigS3_PRESIGNED_PUT_URL         "...insert here..."
 */

/**
 * @brief An option to disable Server Name Indication.
 *
 * @note When using a local server setup, SNI needs to be disabled for a server
 * that only has an IP address but no hostname. However, SNI should be enabled
 * whenever possible.
 */
#define democonfigDISABLE_SNI                       ( pdFALSE )

/**
 * @brief Transport timeout in milliseconds for transport send and receive.
 */
#define democonfigTRANSPORT_SEND_RECV_TIMEOUT_MS    ( 5000 )

/**
 * @brief The length in bytes of the user buffer.
 */
#define democonfigUSER_BUFFER_LENGTH                ( 2048 )

/**
 * @brief Set the stack size of the main demo task.
 *
 * In the Windows port, this stack only holds a structure. The actual
 * stack is created by an operating system thread.
 */
#define democonfigDEMO_STACKSIZE                    configMINIMAL_STACK_SIZE

#endif /* ifndef DEMO_CONFIG_H */
