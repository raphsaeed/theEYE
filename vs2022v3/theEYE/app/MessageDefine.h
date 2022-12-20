#ifndef MESSAGEDEFINE_H
#define MESSAGEDEFINE_H

#include "CRSDK/CrTypes.h"
#include "CRSDK/CrError.h"
#include "Text.h"
#include <unordered_map>

namespace cli
{
    text get_message_desc(CrInt32u code);

    // Error code category
    const std::unordered_map<CrInt32u, text> map_ERR_CAT
    {
        {SCRSDK::CrError_Generic, TEXTx("Generic")},
        {SCRSDK::CrError_File,    TEXTx("File   ")},
        {SCRSDK::CrError_Connect, TEXTx("Connect")},
        {SCRSDK::CrError_Memory,  TEXTx("Memory ")},
        {SCRSDK::CrError_Api,     TEXTx("Api    ")},
        {SCRSDK::CrError_Polling, TEXTx("Polling")},
        {SCRSDK::CrError_Adaptor, TEXTx("Adaptor")},
        {SCRSDK::CrError_Device,  TEXTx("Device ")},
        {SCRSDK::CrError_Contents,TEXTx("Content")},
    };

    // Error code detail
    const std::unordered_map<CrInt32u, text> map_ERR_DETAIL
    {
        {SCRSDK::CrError_Generic_Unknown, TEXTx("Uncategorized errors")},
        {SCRSDK::CrError_Generic_Notimpl, TEXTx("Not implemented")},
        {SCRSDK::CrError_Generic_Abort, TEXTx("Processing was aborted")},
        {SCRSDK::CrError_Generic_NotSupported, TEXTx("Not supported")},
        {SCRSDK::CrError_Generic_SeriousErrorNotSupported, TEXTx("Serious error not supported")},
        {SCRSDK::CrError_Generic_InvalidHandle, TEXTx("Not valid handle")},
        {SCRSDK::CrError_Generic_InvalidParameter, TEXTx("Invalid parameter")},

        {SCRSDK::CrError_File_Unknown, TEXTx("Unknown file errors")},
        {SCRSDK::CrError_File_IllegalOperation, TEXTx("Illegal operation (e.g., loading without opening)")},
        {SCRSDK::CrError_File_IllegalParameter, TEXTx("Illegal parameter")},
        {SCRSDK::CrError_File_EOF, TEXTx("EOF")},
        {SCRSDK::CrError_File_OutOfRange, TEXTx("Operation, such as seek, is out of range")},
        {SCRSDK::CrError_File_NotFound, TEXTx("File not found")},
        {SCRSDK::CrError_File_DirNotFound, TEXTx("Directory not found")},
        {SCRSDK::CrError_File_AlreadyOpened, TEXTx("Already opened")},
        {SCRSDK::CrError_File_PermissionDenied, TEXTx("No access permission")},
        {SCRSDK::CrError_File_StorageFull, TEXTx("Host storage is full")},
        {SCRSDK::CrError_File_AlreadyExists, TEXTx("Already exists")},
        {SCRSDK::CrError_File_TooManyOpenedFiles, TEXTx("Too many open files")},
        {SCRSDK::CrError_File_ReadOnly, TEXTx("Read-Only file")},
        {SCRSDK::CrError_File_CantOpen, TEXTx("Cannot open")},
        {SCRSDK::CrError_File_CantClose, TEXTx("Cannot close")},
        {SCRSDK::CrError_File_CantDelete, TEXTx("Cannot delete")},
        {SCRSDK::CrError_File_CantRead, TEXTx("Cannot read")},
        {SCRSDK::CrError_File_CantWrite, TEXTx("Cannot write")},
        {SCRSDK::CrError_File_CantCreateDir, TEXTx("Cannot create a directory")},
        {SCRSDK::CrError_File_OperationAbortedByUser, TEXTx("Processing was aborted by user")},
        {SCRSDK::CrError_File_UnsupportedOperation, TEXTx("API not supported for the platform was called")},
        {SCRSDK::CrError_File_NotYetCompleted, TEXTx("Operation is not completed")},
        {SCRSDK::CrError_File_Invalid, TEXTx("The file is no longer valid because the volume for the file was altered")},
        {SCRSDK::CrError_File_StorageNotExist, TEXTx("The specified network resource or device is no longer available")},
        {SCRSDK::CrError_File_SharingViolation, TEXTx("Sharing violation")},
        {SCRSDK::CrError_File_Rotation, TEXTx("Invalid file orientation")},
        {SCRSDK::CrError_File_SameNameFull, TEXTx("Too many same-name files")},

        {SCRSDK::CrError_Connect_Unknown, TEXTx("Other errors classified as connection except below")},
        {SCRSDK::CrError_Connect_Connect, TEXTx("A connection request failed through the USB")},
        {SCRSDK::CrError_Connect_Release, TEXTx("Release failed")},
        {SCRSDK::CrError_Connect_GetProperty, TEXTx("Getting property failed")},
        {SCRSDK::CrError_Connect_SendCommand, TEXTx("Sending command failed")},
        {SCRSDK::CrError_Connect_HandlePlugin, TEXTx("Illegal handle plug-in")},
        {SCRSDK::CrError_Connect_Disconnected, TEXTx("A connection disconnected")},
        {SCRSDK::CrError_Connect_TimeOut, TEXTx("A connection operation timed out")},
        {SCRSDK::CrError_Reconnect_TimeOut, TEXTx("Reconnection operations timed out")},
        {SCRSDK::CrError_Connect_FailRejected, TEXTx("Connection rejected and failed")},
        {SCRSDK::CrError_Connect_FailBusy, TEXTx("Connection failed due to processing in progress")},
        {SCRSDK::CrError_Connect_FailUnspecified, TEXTx("Unspecified connection failure")},
        {SCRSDK::CrError_Connect_Cancel, TEXTx("Connection canceled")},
        {SCRSDK::CrError_Connect_SessionAlreadyOpened, TEXTx("A connection failed because camera was not ready")},
        {SCRSDK::CrError_Connect_ContentsTransfer_NotSupported, TEXTx("This camera does not support content transfer")},
        {SCRSDK::CrError_Connect_SSH_NotSupported, TEXTx("SSH not support")},
        {SCRSDK::CrError_Connect_SSH_InvalidParameter, TEXTx("SSH Invalid Parameter")},
        {SCRSDK::CrError_Connect_SSH_ServerConnectFailed, TEXTx("SSH Server connect failed")},
        {SCRSDK::CrError_Connect_SSH_ServerAuthenticationFailed, TEXTx("SSH Server authentication failed")},
        {SCRSDK::CrError_Connect_SSH_UserAuthenticationFailed, TEXTx("SSH User authentication failed")},
        {SCRSDK::CrError_Connect_SSH_PortfowardFailed, TEXTx("SSH Portfoward failed")},
        {SCRSDK::CrError_Connect_SSH_GetFingerprintFailed, TEXTx("SSH get Fingerprint Failed")},

        {SCRSDK::CrError_Memory_Unknown, TEXTx("Unknown memory error")},
        {SCRSDK::CrError_Memory_OutOfMemory, TEXTx("Cannot allocate memory")},
        {SCRSDK::CrError_Memory_InvalidPointer, TEXTx("Invalid pointer")},
        {SCRSDK::CrError_Memory_Insufficient, TEXTx("Allocate memory insufficient")},

        {SCRSDK::CrError_Api_Unknown, TEXTx("Unknown API error")},
        {SCRSDK::CrError_Api_Insufficient, TEXTx("Incorrect parameter")},
        {SCRSDK::CrError_Api_InvalidCalled, TEXTx("Invalid API call")},
        {SCRSDK::CrError_Api_NoApplicableInformation, TEXTx("No corresponding Display String List for the type")},
        {SCRSDK::CrError_Api_OutOfModelList, TEXTx("Outside the scope of the camera model list")},
        {SCRSDK::CrError_Api_NotSupportModelOfUSB, TEXTx("Models that does not support USB connection")},
        {SCRSDK::CrError_Api_NotSupportModelOfEthernet, TEXTx("Models that does not support Ethernet connection")},
        {SCRSDK::CrError_Api_InvalidSerialNumber, TEXTx("Invalid SerialNumber")},
        {SCRSDK::CrError_Api_InvalidIpAddress, TEXTx("Invalid IP Address")},
        {SCRSDK::CrError_Api_InvalidMacAddress, TEXTx("Invalid MAC Address")},

        {SCRSDK::CrError_Polling_Unknown, TEXTx("Unknown polling error")},
        {SCRSDK::CrError_Polling_InvalidVal_Intervals, TEXTx("Invalid polling interval setting value")},

        {SCRSDK::CrError_Adaptor_Unknown, TEXTx("Unknown adapter error")},
        {SCRSDK::CrError_Adaptor_InvaildProperty, TEXTx("A property that doesn't exist was used")},
        {SCRSDK::CrError_Adaptor_GetInfo, TEXTx("Getting information failed")},
        {SCRSDK::CrError_Adaptor_Create, TEXTx("Creation failed")},
        {SCRSDK::CrError_Adaptor_SendCommand, TEXTx("Sending command failed")},
        {SCRSDK::CrError_Adaptor_HandlePlugin, TEXTx("Illegal handle plug-in")},
        {SCRSDK::CrError_Adaptor_CreateDevice, TEXTx("Device creation failed")},
        {SCRSDK::CrError_Adaptor_EnumDevice, TEXTx("Enumeration of device information failed")},
        {SCRSDK::CrError_Adaptor_Reset, TEXTx("Reset failed")},
        {SCRSDK::CrError_Adaptor_Read, TEXTx("Read failed")},
        {SCRSDK::CrError_Adaptor_Phase, TEXTx("Parse failed")},
        {SCRSDK::CrError_Adaptor_DataToWiaItem, TEXTx("Failed to set data as WIA item")},
        {SCRSDK::CrError_Adaptor_DeviceBusy, TEXTx("The setting side is busy")},
        {SCRSDK::CrError_Adaptor_Escape, TEXTx("Escape failed")},

        {SCRSDK::CrError_Contents_Unknown, TEXTx("Unknown content transfer error")},
        {SCRSDK::CrError_Contents_InvalidHandle, TEXTx("Not valid content handle")},
        {SCRSDK::CrError_Contents_DateFolderList_NotRetrieved, TEXTx("Date folder list not acquired")},
        {SCRSDK::CrError_Contents_ContentsList_NotRetrieved, TEXTx("Content handle list not acquired")},
        {SCRSDK::CrError_Contents_Transfer_Unsuccess, TEXTx("Content transfer failed")},
        {SCRSDK::CrError_Contents_Transfer_Cancel,TEXTx("Not transferred due to successful content transfer cancel")},
        {SCRSDK::CrError_Contents_RejectRequest, TEXTx("Rejected request")},

        {SCRSDK::CrError_Device_Unknown, TEXTx("Unknown device error")},
    }; 

} // namespace cli

#endif // !MESSAGEDEFINE_H
