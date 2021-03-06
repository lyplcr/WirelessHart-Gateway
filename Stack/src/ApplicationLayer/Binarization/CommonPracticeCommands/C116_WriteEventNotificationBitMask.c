/*
* Copyright (C) 2013 Nivis LLC.
* Email:   opensource@nivis.com
* Website: http://www.nivis.com
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, version 3 of the License.
* 
* Redistribution and use in source and binary forms must retain this
* copyright notice.

* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
*/

#include "C116_WriteEventNotificationBitMask.h"

uint8_t Compose_C116_WriteEventNotificationBitMask_Req(C116_WriteEventNotificationBitMask_Req* request,
		ComposerContext* context, BinaryStream* toStream)
{
	context->cmdId = CMDID_C116_WriteEventNotificationBitMask;

	STREAM_WRITE_UINT8(toStream, request->eventNo);
	for (uint8_t i = 0; i < request->noOfWriteEvents; i++)
	{
		STREAM_WRITE_UINT8(toStream, request->eventMask[i]);
	}
	return RCS_N00_Success;
}

uint8_t Parse_C116_WriteEventNotificationBitMask_Req(C116_WriteEventNotificationBitMask_Req* request,
		ParserContext* context, BinaryStream* fromStream)
{
	//TODO:[Ovidiu] -add validations
	STREAM_READ_UINT8(fromStream, &request->eventNo);
	request->noOfWriteEvents = fromStream->remainingBytes;
	for (uint8_t i = 0; i < request->noOfWriteEvents; i++)
	{
		STREAM_READ_UINT8(fromStream, &request->eventMask[i]);
	}
	return RCS_N00_Success;
}

uint8_t Compose_C116_WriteEventNotificationBitMask_Resp(C116_WriteEventNotificationBitMask_Resp* response,
		ComposerContext* context, BinaryStream* toStream)
{
	context->cmdId = CMDID_C116_WriteEventNotificationBitMask;

	STREAM_WRITE_UINT8(toStream, response->eventNo);
	for (uint8_t i = 0; i < response->noOfWriteEvents; i++)
	{
		STREAM_WRITE_UINT8(toStream, response->eventMask[i]);
	}
	return RCS_N00_Success;
}

uint8_t Parse_C116_WriteEventNotificationBitMask_Resp(C116_WriteEventNotificationBitMask_Resp* response,
		ParserContext* context, BinaryStream* fromStream)
{
	//TODO:[Ovidiu] -add validations .Response is tuncable
	STREAM_READ_UINT8(fromStream, &response->eventNo);
	response->noOfWriteEvents = fromStream->remainingBytes;
	for (uint8_t i = 0; i < response->noOfWriteEvents; i++)
	{
		STREAM_READ_UINT8(fromStream, &response->eventMask[i]);
	}
	return RCS_N00_Success;
}
