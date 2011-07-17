/* soapagentProxy.cpp
   Generated by gSOAP 2.8.0 from SMC.h
   Copyright(C) 2000-2010, Robert van Engelen, Genivia Inc. All Rights Reserved.
   The generated code is released under one of the following licenses:
   GPL OR Genivia's license for commercial use.
*/

#include "soapagentProxy.h"

agentProxy::agentProxy()
{	agentProxy_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
}

agentProxy::agentProxy(const struct soap &_soap) : soap(_soap)
{ }

agentProxy::agentProxy(soap_mode iomode)
{	agentProxy_init(iomode, iomode);
}

agentProxy::agentProxy(soap_mode imode, soap_mode omode)
{	agentProxy_init(imode, omode);
}

void agentProxy::agentProxy_init(soap_mode imode, soap_mode omode)
{	soap_imode(this, imode);
	soap_omode(this, omode);
	soap_endpoint = NULL;
	static const struct Namespace namespaces[] =
{
	{"SOAP-ENV", "http://schemas.xmlsoap.org/soap/envelope/", "http://www.w3.org/*/soap-envelope", NULL},
	{"SOAP-ENC", "http://schemas.xmlsoap.org/soap/encoding/", "http://www.w3.org/*/soap-encoding", NULL},
	{"xsi", "http://www.w3.org/2001/XMLSchema-instance", "http://www.w3.org/*/XMLSchema-instance", NULL},
	{"xsd", "http://www.w3.org/2001/XMLSchema", "http://www.w3.org/*/XMLSchema", NULL},
	{"camera", "http://tempuri.org/camera.xsd", NULL, NULL},
	{"agent", "http://tempuri.org/agent.xsd", NULL, NULL},
	{"server", "http://tempuri.org/server.xsd", NULL, NULL},
	{NULL, NULL, NULL, NULL}
};
	this->namespaces = namespaces;
}

agentProxy::~agentProxy()
{ }

void agentProxy::destroy()
{	soap_destroy(this);
	soap_end(this);
}

void agentProxy::soap_noheader()
{	header = NULL;
}

const SOAP_ENV__Fault *agentProxy::soap_fault()
{	return this->fault;
}

const char *agentProxy::soap_fault_string()
{	return *soap_faultstring(this);
}

const char *agentProxy::soap_fault_detail()
{	return *soap_faultdetail(this);
}

int agentProxy::soap_close_socket()
{	return soap_closesock(this);
}

void agentProxy::soap_print_fault(FILE *fd)
{	::soap_print_fault(this, fd);
}

#ifndef WITH_LEAN
void agentProxy::soap_stream_fault(std::ostream& os)
{	::soap_stream_fault(this, os);
}

char *agentProxy::soap_sprint_fault(char *buf, size_t len)
{	return ::soap_sprint_fault(this, buf, len);
}
#endif

int agentProxy::coreStation(std::string command, std::string &message)
{	struct soap *soap = this;
	struct agent__coreStation soap_tmp_agent__coreStation;
	struct agent__coreStationResponse *soap_tmp_agent__coreStationResponse;
	const char *soap_action = NULL;
	soap->encodingStyle = NULL;
	soap_tmp_agent__coreStation.command = command;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_agent__coreStation(soap, &soap_tmp_agent__coreStation);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_agent__coreStation(soap, &soap_tmp_agent__coreStation, "agent:coreStation", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_agent__coreStation(soap, &soap_tmp_agent__coreStation, "agent:coreStation", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&message)
		return soap_closesock(soap);
	soap_default_std__string(soap, &message);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_tmp_agent__coreStationResponse = soap_get_agent__coreStationResponse(soap, NULL, "agent:coreStationResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	message = soap_tmp_agent__coreStationResponse->message;
	return soap_closesock(soap);
}

int agentProxy::addCamera(std::string uuid, std::string &message)
{	struct soap *soap = this;
	struct agent__addCamera soap_tmp_agent__addCamera;
	struct agent__addCameraResponse *soap_tmp_agent__addCameraResponse;
	const char *soap_action = NULL;
	soap->encodingStyle = NULL;
	soap_tmp_agent__addCamera.uuid = uuid;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_agent__addCamera(soap, &soap_tmp_agent__addCamera);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_agent__addCamera(soap, &soap_tmp_agent__addCamera, "agent:addCamera", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_agent__addCamera(soap, &soap_tmp_agent__addCamera, "agent:addCamera", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&message)
		return soap_closesock(soap);
	soap_default_std__string(soap, &message);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_tmp_agent__addCameraResponse = soap_get_agent__addCameraResponse(soap, NULL, "agent:addCameraResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	message = soap_tmp_agent__addCameraResponse->message;
	return soap_closesock(soap);
}

int agentProxy::removeCamera(std::string uuid, std::string &message)
{	struct soap *soap = this;
	struct agent__removeCamera soap_tmp_agent__removeCamera;
	struct agent__removeCameraResponse *soap_tmp_agent__removeCameraResponse;
	const char *soap_action = NULL;
	soap->encodingStyle = NULL;
	soap_tmp_agent__removeCamera.uuid = uuid;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_agent__removeCamera(soap, &soap_tmp_agent__removeCamera);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_agent__removeCamera(soap, &soap_tmp_agent__removeCamera, "agent:removeCamera", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_agent__removeCamera(soap, &soap_tmp_agent__removeCamera, "agent:removeCamera", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&message)
		return soap_closesock(soap);
	soap_default_std__string(soap, &message);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_tmp_agent__removeCameraResponse = soap_get_agent__removeCameraResponse(soap, NULL, "agent:removeCameraResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	message = soap_tmp_agent__removeCameraResponse->message;
	return soap_closesock(soap);
}

int agentProxy::setCameraInfo(struct camera__info *_info, std::string &message)
{	struct soap *soap = this;
	struct agent__setCameraInfo soap_tmp_agent__setCameraInfo;
	struct agent__setCameraInfoResponse *soap_tmp_agent__setCameraInfoResponse;
	const char *soap_action = NULL;
	soap->encodingStyle = NULL;
	soap_tmp_agent__setCameraInfo._info = _info;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_agent__setCameraInfo(soap, &soap_tmp_agent__setCameraInfo);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_agent__setCameraInfo(soap, &soap_tmp_agent__setCameraInfo, "agent:setCameraInfo", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_agent__setCameraInfo(soap, &soap_tmp_agent__setCameraInfo, "agent:setCameraInfo", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&message)
		return soap_closesock(soap);
	soap_default_std__string(soap, &message);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_tmp_agent__setCameraInfoResponse = soap_get_agent__setCameraInfoResponse(soap, NULL, "agent:setCameraInfoResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	message = soap_tmp_agent__setCameraInfoResponse->message;
	return soap_closesock(soap);
}

int agentProxy::setCameraURI(struct camera__uri *_info, std::string &message)
{	struct soap *soap = this;
	struct agent__setCameraURI soap_tmp_agent__setCameraURI;
	struct agent__setCameraURIResponse *soap_tmp_agent__setCameraURIResponse;
	const char *soap_action = NULL;
	soap->encodingStyle = NULL;
	soap_tmp_agent__setCameraURI._info = _info;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_agent__setCameraURI(soap, &soap_tmp_agent__setCameraURI);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_agent__setCameraURI(soap, &soap_tmp_agent__setCameraURI, "agent:setCameraURI", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_agent__setCameraURI(soap, &soap_tmp_agent__setCameraURI, "agent:setCameraURI", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&message)
		return soap_closesock(soap);
	soap_default_std__string(soap, &message);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_tmp_agent__setCameraURIResponse = soap_get_agent__setCameraURIResponse(soap, NULL, "agent:setCameraURIResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	message = soap_tmp_agent__setCameraURIResponse->message;
	return soap_closesock(soap);
}
/* End of client proxy code */