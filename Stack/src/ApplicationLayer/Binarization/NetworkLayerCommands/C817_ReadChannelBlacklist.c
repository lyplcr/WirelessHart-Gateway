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

#include "C817_ReadChannelBlacklist.h"

uint8_t Compose_C817_ReadChannelBlacklist_Req ( C817_ReadChannelBlacklist_Req* request,
                                    ComposerContext* context,
                                    BinaryStream* toStream )
{
  context->cmdId = CMDID_C817_ReadChannelBlacklist;

  return RCS_N00_Success; // success
}

uint8_t Parse_C817_ReadChannelBlacklist_Req ( C817_ReadChannelBlacklist_Req* request,
                                    ParserContext* context,
		                    BinaryStream* fromStream )
{
#if defined(_DEBUG)
//   if (fromStream->remainingBytes > 0)
//     return RCS_E01_Undefined1; // too many bytes
#endif

  return RCS_N00_Success; // success
}

uint8_t Compose_C817_ReadChannelBlacklist_Resp ( C817_ReadChannelBlacklist_Resp* response,
                                    ComposerContext* context,
                                    BinaryStream* toStream )
{
  context->cmdId = CMDID_C817_ReadChannelBlacklist;
  STREAM_WRITE_UINT8(toStream, response->m_ucNoOfBitsInCurrentChannelMapArray);
  STREAM_WRITE_UINT16(toStream, response->m_unCurrentChannelMapArray);
  STREAM_WRITE_UINT16(toStream, response->m_unPendingChannelMapArray);

  return RCS_N00_Success; // success
}

uint8_t Parse_C817_ReadChannelBlacklist_Resp ( C817_ReadChannelBlacklist_Resp* response,
                                    ParserContext* context,
		                    BinaryStream* fromStream )
{
#if defined(_DEBUG)
//   if (fromStream->remainingBytes > C817_RespSize)
//     return RCS_E01_Undefined1; // too many bytes
#endif

  STREAM_READ_UINT8(fromStream, &response->m_ucNoOfBitsInCurrentChannelMapArray);
  STREAM_READ_UINT16(fromStream, &response->m_unCurrentChannelMapArray);
  STREAM_READ_UINT16(fromStream, &response->m_unPendingChannelMapArray);

  return RCS_N00_Success; // success
}
