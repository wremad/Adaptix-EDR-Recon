#include "../include/beacon.h"
#include "../include/edr.h"

#include <windows.h>
#include <stdio.h>

DECLSPEC_IMPORT SC_HANDLE WINAPI ADVAPI32$OpenSCManagerA(
    LPCSTR lpMachineName,
    LPCSTR lpDatabaseName,
    DWORD dwDesiredAccess
);

DECLSPEC_IMPORT SC_HANDLE WINAPI ADVAPI32$OpenServiceA(
    SC_HANDLE hSCManager,
    LPCSTR lpServiceName,
    DWORD dwDesiredAccess
);

DECLSPEC_IMPORT BOOL WINAPI ADVAPI32$CloseServiceHandle(
    SC_HANDLE hSCObject
);

void enum_services()
{
    SC_HANDLE scm;

    scm = ADVAPI32$OpenSCManagerA(
        NULL,
        NULL,
        SC_MANAGER_CONNECT
    );

    if (!scm)
    {
        BeaconPrintf(CALLBACK_ERROR,
            "[!] Failed to open SCM\n");
        return;
    }

    BeaconPrintf(CALLBACK_OUTPUT,
        "========================================\n");
    BeaconPrintf(CALLBACK_OUTPUT,
        "     EDR / AV SERVICE ENUMERATION\n");
    BeaconPrintf(CALLBACK_OUTPUT,
        "========================================\n\n");

    for (int i = 0; i < EDR_COUNT; i++)
    {
        SC_HANDLE svc;

        svc = ADVAPI32$OpenServiceA(
            scm,
            edr_list[i].service_name,
            SERVICE_QUERY_STATUS
        );

        if (svc)
        {
            BeaconPrintf(
                CALLBACK_OUTPUT,
                "[+] FOUND: %-25s | Service: %s\n",
                edr_list[i].product,
                edr_list[i].service_name
            );

            ADVAPI32$CloseServiceHandle(svc);
        }
    }

    ADVAPI32$CloseServiceHandle(scm);
}

void go(char *args, int len)
{
    BeaconPrintf(CALLBACK_OUTPUT,
        "[*] Starting EDR enumeration...\n\n");

    enum_services();

    BeaconPrintf(CALLBACK_OUTPUT,
        "\n[*] Enumeration completed.\n");
}
