/*
 *					MXit Protocol libPurple Plugin
 *
 *			-- MXit client protocol implementation --
 *
 *				Pieter Loubser	<libpurple@mxit.com>
 *
 *			(C) Copyright 2009	MXit Lifestyle (Pty) Ltd.
 *				<http://www.mxitlifestyle.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02111-1301  USA
 */

#ifndef		_MXIT_PROTO_H_
#define		_MXIT_PROTO_H_


/* Client protocol constants */
#define		CP_SOCK_REC_TERM		'\x00'				/* socket record terminator */
#define		CP_HTTP_REC_TERM		'\x26'				/* http record terminator '&' */
#define		CP_FLD_TERM				'\x01'				/* field terminator */
#define		CP_PKT_TERM				'\x02'				/* packet terminator */


#define		CP_MAX_PACKET			( 1024 * 1024 )		/* maximum client protocol packet size (1 MiB) */
#define		CP_MAX_FILESIZE			( 150 * 1000 )		/* maximum client protocol file transfer size (150 KB) */
#define		MXIT_EMOTICON_SIZE		18					/* icon size for custom emoticons */
#define		CP_MAX_STATUS_MSG		250					/* maximum status message length (in characters) */

/* Avatars */
#define		MXIT_AVATAR_SIZE		96					/* default avatar image size 96x96 */
#define		MXIT_AVATAR_TYPE		"PNG"				/* request avatars in this file type (only a suggestion) */
#define		MXIT_AVATAR_BITDEPT		24					/* request avatars with this bit depth (only a suggestion) */

/* Protocol error codes */
#define		MXIT_ERRCODE_SUCCESS	0
#define		MXIT_ERRCODE_REDIRECT	16
#define		MXIT_ERRCODE_LOGGEDOUT	42

/* MXit client features */
#define		MXIT_CF_NONE			0x000000
#define		MXIT_CF_FORMS			0x000001
#define		MXIT_CF_FILE_TRANSFER	0x000002
#define		MXIT_CF_CAMERA			0x000004
#define		MXIT_CF_COMMANDS		0x000008
#define		MXIT_CF_SMS				0x000010
#define		MXIT_CF_FILE_ACCESS		0x000020
#define		MXIT_CF_MIDP2			0x000040
#define		MXIT_CF_SKINS			0x000080
#define		MXIT_CF_AUDIO			0x000100
#define		MXIT_CF_ENCRYPTION		0x000200
#define		MXIT_CF_VOICE_REC		0x000400
#define		MXIT_CF_VECTOR_GFX		0x000800
#define		MXIT_CF_IMAGES			0x001000
#define		MXIT_CF_MARKUP			0x002000
#define		MXIT_CF_VIBES			0x004000
#define		MXIT_CF_SELECT_CONTACT	0x008000
#define		MXIT_CF_CUSTOM_EMO		0x010000
#define		MXIT_CF_ALERT_PROFILES	0x020000
#define		MXIT_CF_EXT_MARKUP		0x040000
#define		MXIT_CF_PLAIN_PWD		0x080000
#define		MXIT_CF_NO_GATEWAYS		0x100000
#define		MXIT_CF_NO_AVATARS		0x200000
#define		MXIT_CF_GAMING			0x400000
#define		MXIT_CF_GAMING_UPDATE	0x800000

/* Client features supported by this implementation */
#define		MXIT_CP_FEATURES		( MXIT_CF_FILE_TRANSFER | MXIT_CF_FILE_ACCESS | MXIT_CF_AUDIO | MXIT_CF_MARKUP | MXIT_CF_EXT_MARKUP | MXIT_CF_NO_GATEWAYS | MXIT_CF_IMAGES | MXIT_CF_COMMANDS | MXIT_CF_VIBES | MXIT_CF_MIDP2 )


#define		MXIT_PING_INTERVAL		( 5 * 60 )				/* ping the server after X seconds of being idle (5 minutes) */
#define		MXIT_ACK_TIMEOUT		( 30 )					/* timeout after waiting X seconds for an ack from the server (30 seconds) */

/* MXit client version */
#define		MXIT_CP_DISTCODE		"P"						/* client distribution code (magic, do not touch!) */
#define		MXIT_CP_RELEASE			"5.9.0"					/* client version */
#define		MXIT_CP_ARCH			"Y"						/* client architecture series (Y not for Yoda but for PC-client) */
#define		MXIT_CLIENT_ID			"LP"					/* client ID as specified by MXit */
#define		MXIT_CP_PLATFORM		"PURPLE"				/* client platform */
#define		MXIT_CP_VERSION			MXIT_CP_DISTCODE"-"MXIT_CP_RELEASE"-"MXIT_CP_ARCH"-"MXIT_CP_PLATFORM
#define		MXIT_CP_PROTO_VESION	60						/* client protocol version */

/* set operating system name */
#if defined( __APPLE__ )
#define		MXIT_CP_OS				"apple"
#elif defined( _WIN32 )
#define		MXIT_CP_OS				"windows"
#elif defined( __linux__ )
#define		MXIT_CP_OS				"linux"
#else
#define		MXIT_CP_OS				"unknown"
#endif

/* Client capabilities */
#define		MXIT_CP_CAP				"utf8=true;cid="MXIT_CLIENT_ID

/* Client settings */
#define		MAX_QUEUE_SIZE			( 1 << 4 )				/* tx queue size (16 packets) */
#define		MXIT_POPUP_WIN_NAME		"MXit Notification"		/* popup window name */
#define		MXIT_MAX_ATTRIBS		10						/* maximum profile attributes supported */
#define		MXIT_DEFAULT_LOCALE		"en"					/* default locale setting */
#define		MXIT_DEFAULT_LOC		"planetpurple"			/* the default location for registration */

/* Client protocol commands */
#define		CP_CMD_LOGIN			0x0001					/* (1) login */
#define		CP_CMD_LOGOUT			0x0002					/* (2) logout */
#define		CP_CMD_CONTACT			0x0003					/* (3) get contacts */
#define		CP_CMD_UPDATE			0x0005					/* (5) update contact information */
#define		CP_CMD_INVITE			0x0006					/* (6) subscribe to new contact */
#define		CP_CMD_PRESENCE			0x0007					/* (7) get presence */
#define		CP_CMD_REMOVE			0x0008					/* (8) remove contact */
#define		CP_CMD_RX_MSG			0x0009					/* (9) get new messages */
#define		CP_CMD_TX_MSG			0x000A					/* (10) send new message */
#define		CP_CMD_REGISTER			0x000B					/* (11) register */
//#define	CP_CMD_PROFILE_SET		0x000C					/* (12) set profile (DEPRECATED see CP_CMD_EXTPROFILE_SET) */
#define		CP_CMD_POLL				0x0011					/* (17) poll the HTTP server for an update */
//#define	CP_CMD_PROFILE_GET		0x001A					/* (26) get profile (DEPRECATED see CP_CMD_EXTPROFILE_GET) */
#define		CP_CMD_MEDIA			0x001B					/* (27) get multimedia message */
#define		CP_CMD_SPLASHCLICK		0x001F					/* (31) splash-screen clickthrough */
#define		CP_CMD_STATUS			0x0020					/* (32) set shown presence & status */
#define		CP_CMD_MSGEVENT			0x0023					/* (35) Raise message event */ 
#define		CP_CMD_MOOD				0x0029					/* (41) set mood */
#define		CP_CMD_KICK				0x002B					/* (43) login kick */
#define		CP_CMD_GRPCHAT_CREATE	0x002C					/* (44) create new groupchat */
#define		CP_CMD_GRPCHAT_INVITE	0x002D					/* (45) add new groupchat member */
#define		CP_CMD_NEW_SUB			0x0033					/* (51) get new subscription */
#define		CP_CMD_ALLOW			0x0034					/* (52) allow subscription */
#define		CP_CMD_DENY				0x0037					/* (55) deny subscription */
#define		CP_CMD_EXTPROFILE_GET	0x0039					/* (57) get extended profile */
#define		CP_CMD_EXTPROFILE_SET	0x003A					/* (58) set extended profile */
#define		CP_CMD_PING				0x03E8					/* (1000) ping (keepalive) */

/* HTTP connection */
#define		MXIT_HTTP_POLL_MIN		7						/* minimum time between HTTP polls (seconds) */
#define		MXIT_HTTP_POLL_MAX		( 10 * 60 )				/* maximum time between HTTP polls (seconds) */

/* receiver states */
#define		RX_STATE_RLEN			0x01					/* reading packet length section */
#define		RX_STATE_DATA			0x02					/* reading packet data section */
#define		RX_STATE_PROC			0x03					/* process read data */

/* message flags */
#define		CP_MSG_NOTIFY_DELIVERY	0x0002					/* request delivery notification */
#define		CP_MSG_NOTIFY_READ		0x0004					/* request read notification */
#define		CP_MSG_ENCRYPTED		0x0010					/* message is encrypted */
#define		CP_MSG_MARKUP			0x0200					/* message may contain markup */
#define		CP_MSG_EMOTICON			0x0400					/* message may contain custom emoticons */

/* redirect types */
#define		CP_REDIRECT_PERMANENT	1						/* permanent redirect */
#define		CP_REDIRECT_TEMPORARY	2						/* temporary redirect */

/* message tx types */
#define		CP_MSGTYPE_NORMAL		0x01					/* normal message */
#define		CP_MSGTYPE_CHAT			0x02					/* chat message */
#define		CP_MSGTYPE_HEADLINE		0x03					/* headline message */
#define		CP_MSGTYPE_ERROR		0x04					/* error message */
#define		CP_MSGTYPE_GROUPCHAT	0x05					/* groupchat message */
#define		CP_MSGTYPE_FORM			0x06					/* mxit custom form */
#define		CP_MSGTYPE_COMMAND		0x07					/* mxit command */

/* message event types */
#define		CP_MSGEVENT_DELIVERED	0x02					/* message was delivered */
#define		CP_MSGEVENT_DISPLAYED	0x04					/* message was viewed */

/* extended profile attribute fields */
#define		CP_PROFILE_BIRTHDATE	"birthdate"				/* Birthdate (String - ISO 8601 format) */
#define		CP_PROFILE_GENDER		"gender"				/* Gender (Boolean - 0=female, 1=male) */
#define		CP_PROFILE_HIDENUMBER	"hidenumber"			/* Hide Number (Boolean - 0=false, 1=true) */
#define		CP_PROFILE_FULLNAME		"fullname"				/* Fullname (UTF8 String) */
#define		CP_PROFILE_STATUS		"statusmsg"				/* Status Message (UTF8 String) */
#define		CP_PROFILE_PREVSTATUS	"prevstatusmsgs"		/* Previous Status Messages (UTF8 String) */
#define		CP_PROFILE_AVATAR		"avatarid"				/* Avatar ID (String) */
#define		CP_PROFILE_MODIFIED		"lastmodified"			/* Last-Modified timestamp */
#define		CP_PROFILE_TITLE		"title"					/* Title (UTF8 String) */
#define		CP_PROFILE_FIRSTNAME	"firstname"				/* First name (UTF8 String) */
#define		CP_PROFILE_LASTNAME		"lastname"				/* Last name (UTF8 String) */
#define		CP_PROFILE_EMAIL		"email"					/* Email address (UTF8 String) */
#define		CP_PROFILE_MOBILENR		"mobilenumber"			/* Mobile Number (UTF8 String) */
#define		CP_PROFILE_REGCOUNTRY	"registeredcountry"		/* Registered Country Code (UTF8 String) */
#define		CP_PROFILE_FLAGS		"flags"					/* Profile flags (Bitset) */
#define		CP_PROFILE_LASTSEEN		"lastseen"				/* Last-Online timestamp */

/* extended profile field types */
#define		CP_PROFILE_TYPE_BOOL	0x02					/* boolean profile attribute type */
#define		CP_PROFILE_TYPE_INT		0x05					/* integer profile attribute type */
#define		CP_PROFILE_TYPE_UTF8	0x0A					/* UTF8 string profile attribute type */
#define		CP_PROFILE_TYPE_DATE	0x0B					/* date-time profile attribute type */

/* profile flags */
#define		CP_PROF_DOBLOCKED		0x40					/* date-of-birth cannot be changed */

/* define this to enable protocol debugging (very verbose logging) */
#define		DEBUG_PROTOCOL


/* ======================================================================================= */

struct MXitSession;

/*------------------------------------------*/

struct field {
	char*				data;
	int					len;
};

struct record {
	struct field**		fields;
	int					fcount;
};

struct rx_packet {
	int					cmd;
	int					errcode;
	char*				errmsg;
	struct record**		records;
	int					rcount;
};

struct tx_packet {
	int					cmd;
	char				header[256];
	int					headerlen;
	char*				data;
	int					datalen;
};

/*------------------------------------------*/


/*
 * A received message data object
 */
struct RXMsgData {
	struct MXitSession*		session;					/* MXit session object */
	char*					from;						/* the sender's name */
	time_t					timestamp;					/* time at which the message was sent */
	GString*				msg;						/* newly created message converted to libPurple formatting */
	gboolean				got_img;					/* flag to say if this message got any images/emoticons embedded */
	short					img_count;					/* the amount of images/emoticons still outstanding for the message */
	int						chatid;						/* multimx chatroom id */
	int						flags;						/* libPurple conversation flags */
	gboolean				converted;					/* true if the message has been completely parsed and converted to libPurple markup */
	gboolean				processed;					/* the message has been processed completely and should be freed up */
};



/*
 * The packet transmission queue.
 */
struct tx_queue {
	struct tx_packet*	packets[MAX_QUEUE_SIZE];		/* array of packet pointers */
	int					count;							/* number of packets queued */
	int					rd_i;							/* queue current read index (queue offset for reading a packet) */
	int					wr_i;							/* queue current write index (queue offset for adding new packet) */
};


/* ======================================================================================= */

void mxit_popup( int type, const char* heading, const char* message );
void mxit_strip_domain( char* username );
gboolean find_active_chat( const GList* chats, const char* who );

void mxit_cb_rx( gpointer data, gint source, PurpleInputCondition cond );
gboolean mxit_manage_queue( gpointer user_data );
gboolean mxit_manage_polling( gpointer user_data );

void mxit_send_register( struct MXitSession* session );
void mxit_send_login( struct MXitSession* session );
void mxit_send_logout( struct MXitSession* session );
void mxit_send_ping( struct MXitSession* session );
void mxit_send_poll( struct MXitSession* session );

void mxit_send_presence( struct MXitSession* session, int presence, const char* statusmsg );
void mxit_send_mood( struct MXitSession* session, int mood );
void mxit_send_message( struct MXitSession* session, const char* to, const char* msg, gboolean parse_markup, gboolean is_command );

void mxit_send_extprofile_update( struct MXitSession* session, const char* password, unsigned int nr_attrib, const char* attributes );
void mxit_send_extprofile_request( struct MXitSession* session, const char* username, unsigned int nr_attrib, const char* attribute[] );

void mxit_send_invite( struct MXitSession* session, const char* username, const char* alias, const char* groupname );
void mxit_send_remove( struct MXitSession* session, const char* username );
void mxit_send_allow_sub( struct MXitSession* session, const char* username, const char* alias );
void mxit_send_deny_sub( struct MXitSession* session, const char* username );
void mxit_send_update_contact( struct MXitSession* session, const char* username, const char* alias, const char* groupname );
void mxit_send_splashclick( struct MXitSession* session, const char* splashid );
void mxit_send_msgevent( struct MXitSession* session, const char* to, const char* id, int event);

void mxit_send_file( struct MXitSession* session, const char* username, const char* filename, const unsigned char* buf, int buflen );
void mxit_send_file_reject( struct MXitSession* session, const char* fileid );
void mxit_send_file_accept( struct MXitSession* session, const char* fileid, int filesize, int offset );
void mxit_send_file_received( struct MXitSession* session, const char* fileid, short status );
void mxit_set_avatar( struct MXitSession* session, const unsigned char* avatar, int avatarlen );
void mxit_get_avatar( struct MXitSession* session, const char* mxitId, const char* avatarId );

void mxit_send_groupchat_create( struct MXitSession* session, const char* groupname, int nr_usernames, const char* usernames[] );
void mxit_send_groupchat_invite( struct MXitSession* session, const char* roomid, int nr_usernames, const char* usernames[] );

int mxit_parse_packet( struct MXitSession* session );
void dump_bytes( struct MXitSession* session, const char* buf, int len );
void mxit_close_connection( struct MXitSession* session );


#endif		/* _MXIT_PROTO_H_ */

