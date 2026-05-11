#ifndef EDR_H
#define EDR_H

typedef struct _EDR_ENTRY
{
    char *product;
    char *service_name;
} EDR_ENTRY;

EDR_ENTRY edr_list[] =
{
    {"CrowdStrike Falcon", "CSFalconService"},
    {"Microsoft Defender", "WinDefend"},
    {"SentinelOne", "SentinelAgent"},
    {"Carbon Black", "CarbonBlack"},
    {"Sophos Intercept X", "Sophos Endpoint Defense Service"},
    {"Cylance", "CylanceSvc"},
    {"Trend Micro", "ntrtscan"},
    {"Symantec Endpoint", "SepMasterService"},
    {"McAfee", "McShield"},
    {"K7 Security", "K7TSecurity"},
    {"Kaspersky", "AVP"},
    {"Bitdefender", "EPProtectedService"},
    {"ESET", "ekrn"},
    {"Palo Alto Cortex", "xdrhealthhelper"},
    {"FireEye HX", "xagt"},
    {"VMware Carbon Black", "CbDefense"},
    {"Elastic Endpoint", "ElasticEndpoint"},
    {"SecureWorks", "SWService"},
    {"Cisco AMP", "CiscoAMP"},
    {"FortiEDR", "FortiEDR"},
    {"Check Point", "EPWD"},
    {"Trellix", "TrellixEDR"},
    {"Cybereason", "CybereasonActiveProbe"},
    {"Malwarebytes", "MBAMService"},
    {"Deep Instinct", "DeepInstinct"},
    {"WithSecure", "FSORSPClient"},
    {"Panda Security", "PSANHost"},
    {"AhnLab", "V3Svc"},
    {"Quick Heal", "QuickHeal"},
    {"Avast", "AvastSvc"},
    {"AVG", "AVG Antivirus"},
    {"Avira", "Avira.ServiceHost"}
};

#define EDR_COUNT (sizeof(edr_list) / sizeof(EDR_ENTRY))

#endif
