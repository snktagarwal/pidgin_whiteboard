/* Generated by ../../../libpurple/dbus-analyze-functions.py.  Do not edit! */
static DBusMessage*
music_messaging_change_request_DBUS(DBusMessage *message_DBUS, DBusError *error_DBUS) {
	DBusMessage *reply_DBUS;
	dbus_int32_t session;
	const char *command;
	const char *parameters;
	dbus_message_get_args(message_DBUS, error_DBUS, DBUS_TYPE_INT32, &session, DBUS_TYPE_STRING, &command, DBUS_TYPE_STRING, &parameters, DBUS_TYPE_INVALID);
	CHECK_ERROR(error_DBUS);
	command = (command && command[0]) ? command : NULL;
	parameters = (parameters && parameters[0]) ? parameters : NULL;
	music_messaging_change_request(session, command, parameters);
	reply_DBUS = dbus_message_new_method_return (message_DBUS);
	dbus_message_append_args(reply_DBUS, DBUS_TYPE_INVALID);
	return reply_DBUS;
}

static DBusMessage*
music_messaging_change_confirmed_DBUS(DBusMessage *message_DBUS, DBusError *error_DBUS) {
	DBusMessage *reply_DBUS;
	dbus_int32_t session;
	const char *command;
	const char *parameters;
	dbus_message_get_args(message_DBUS, error_DBUS, DBUS_TYPE_INT32, &session, DBUS_TYPE_STRING, &command, DBUS_TYPE_STRING, &parameters, DBUS_TYPE_INVALID);
	CHECK_ERROR(error_DBUS);
	command = (command && command[0]) ? command : NULL;
	parameters = (parameters && parameters[0]) ? parameters : NULL;
	music_messaging_change_confirmed(session, command, parameters);
	reply_DBUS = dbus_message_new_method_return (message_DBUS);
	dbus_message_append_args(reply_DBUS, DBUS_TYPE_INVALID);
	return reply_DBUS;
}

static DBusMessage*
music_messaging_change_failed_DBUS(DBusMessage *message_DBUS, DBusError *error_DBUS) {
	DBusMessage *reply_DBUS;
	dbus_int32_t session;
	const char *id;
	const char *command;
	const char *parameters;
	dbus_message_get_args(message_DBUS, error_DBUS, DBUS_TYPE_INT32, &session, DBUS_TYPE_STRING, &id, DBUS_TYPE_STRING, &command, DBUS_TYPE_STRING, &parameters, DBUS_TYPE_INVALID);
	CHECK_ERROR(error_DBUS);
	id = (id && id[0]) ? id : NULL;
	command = (command && command[0]) ? command : NULL;
	parameters = (parameters && parameters[0]) ? parameters : NULL;
	music_messaging_change_failed(session, id, command, parameters);
	reply_DBUS = dbus_message_new_method_return (message_DBUS);
	dbus_message_append_args(reply_DBUS, DBUS_TYPE_INVALID);
	return reply_DBUS;
}

static DBusMessage*
music_messaging_done_session_DBUS(DBusMessage *message_DBUS, DBusError *error_DBUS) {
	DBusMessage *reply_DBUS;
	dbus_int32_t session;
	dbus_message_get_args(message_DBUS, error_DBUS, DBUS_TYPE_INT32, &session, DBUS_TYPE_INVALID);
	CHECK_ERROR(error_DBUS);
	music_messaging_done_session(session);
	reply_DBUS = dbus_message_new_method_return (message_DBUS);
	dbus_message_append_args(reply_DBUS, DBUS_TYPE_INVALID);
	return reply_DBUS;
}

static PurpleDBusBinding bindings_DBUS[] = { 
{"MusicMessagingChangeRequest", "in\0i\0session\0in\0s\0command\0in\0s\0parameters\0", music_messaging_change_request_DBUS},
{"MusicMessagingChangeConfirmed", "in\0i\0session\0in\0s\0command\0in\0s\0parameters\0", music_messaging_change_confirmed_DBUS},
{"MusicMessagingChangeFailed", "in\0i\0session\0in\0s\0id\0in\0s\0command\0in\0s\0parameters\0", music_messaging_change_failed_DBUS},
{"MusicMessagingDoneSession", "in\0i\0session\0", music_messaging_done_session_DBUS},
{NULL, NULL, NULL}
};
#define PURPLE_DBUS_REGISTER_BINDINGS(handle) purple_dbus_register_bindings(handle, bindings_DBUS)