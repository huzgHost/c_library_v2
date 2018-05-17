#pragma once
// MESSAGE PESTICIDES PACKING

#define MAVLINK_MSG_ID_PESTICIDES 335

MAVPACKED(
typedef struct __mavlink_pesticides_t {
 uint8_t opened; /*< open action flag*/
 uint8_t capacity; /*< pesticides capacity*/
 uint8_t duty; /*< action pwm duty*/
}) mavlink_pesticides_t;

#define MAVLINK_MSG_ID_PESTICIDES_LEN 3
#define MAVLINK_MSG_ID_PESTICIDES_MIN_LEN 3
#define MAVLINK_MSG_ID_335_LEN 3
#define MAVLINK_MSG_ID_335_MIN_LEN 3

#define MAVLINK_MSG_ID_PESTICIDES_CRC 45
#define MAVLINK_MSG_ID_335_CRC 45



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_PESTICIDES { \
    335, \
    "PESTICIDES", \
    3, \
    {  { "opened", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_pesticides_t, opened) }, \
         { "capacity", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_pesticides_t, capacity) }, \
         { "duty", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_pesticides_t, duty) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_PESTICIDES { \
    "PESTICIDES", \
    3, \
    {  { "opened", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_pesticides_t, opened) }, \
         { "capacity", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_pesticides_t, capacity) }, \
         { "duty", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_pesticides_t, duty) }, \
         } \
}
#endif

/**
 * @brief Pack a pesticides message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param opened open action flag
 * @param capacity pesticides capacity
 * @param duty action pwm duty
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_pesticides_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t opened, uint8_t capacity, uint8_t duty)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PESTICIDES_LEN];
    _mav_put_uint8_t(buf, 0, opened);
    _mav_put_uint8_t(buf, 1, capacity);
    _mav_put_uint8_t(buf, 2, duty);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PESTICIDES_LEN);
#else
    mavlink_pesticides_t packet;
    packet.opened = opened;
    packet.capacity = capacity;
    packet.duty = duty;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PESTICIDES_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_PESTICIDES;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_PESTICIDES_MIN_LEN, MAVLINK_MSG_ID_PESTICIDES_LEN, MAVLINK_MSG_ID_PESTICIDES_CRC);
}

/**
 * @brief Pack a pesticides message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param opened open action flag
 * @param capacity pesticides capacity
 * @param duty action pwm duty
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_pesticides_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t opened,uint8_t capacity,uint8_t duty)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PESTICIDES_LEN];
    _mav_put_uint8_t(buf, 0, opened);
    _mav_put_uint8_t(buf, 1, capacity);
    _mav_put_uint8_t(buf, 2, duty);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PESTICIDES_LEN);
#else
    mavlink_pesticides_t packet;
    packet.opened = opened;
    packet.capacity = capacity;
    packet.duty = duty;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PESTICIDES_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_PESTICIDES;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_PESTICIDES_MIN_LEN, MAVLINK_MSG_ID_PESTICIDES_LEN, MAVLINK_MSG_ID_PESTICIDES_CRC);
}

/**
 * @brief Encode a pesticides struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param pesticides C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_pesticides_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_pesticides_t* pesticides)
{
    return mavlink_msg_pesticides_pack(system_id, component_id, msg, pesticides->opened, pesticides->capacity, pesticides->duty);
}

/**
 * @brief Encode a pesticides struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param pesticides C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_pesticides_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_pesticides_t* pesticides)
{
    return mavlink_msg_pesticides_pack_chan(system_id, component_id, chan, msg, pesticides->opened, pesticides->capacity, pesticides->duty);
}

/**
 * @brief Send a pesticides message
 * @param chan MAVLink channel to send the message
 *
 * @param opened open action flag
 * @param capacity pesticides capacity
 * @param duty action pwm duty
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_pesticides_send(mavlink_channel_t chan, uint8_t opened, uint8_t capacity, uint8_t duty)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PESTICIDES_LEN];
    _mav_put_uint8_t(buf, 0, opened);
    _mav_put_uint8_t(buf, 1, capacity);
    _mav_put_uint8_t(buf, 2, duty);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PESTICIDES, buf, MAVLINK_MSG_ID_PESTICIDES_MIN_LEN, MAVLINK_MSG_ID_PESTICIDES_LEN, MAVLINK_MSG_ID_PESTICIDES_CRC);
#else
    mavlink_pesticides_t packet;
    packet.opened = opened;
    packet.capacity = capacity;
    packet.duty = duty;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PESTICIDES, (const char *)&packet, MAVLINK_MSG_ID_PESTICIDES_MIN_LEN, MAVLINK_MSG_ID_PESTICIDES_LEN, MAVLINK_MSG_ID_PESTICIDES_CRC);
#endif
}

/**
 * @brief Send a pesticides message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_pesticides_send_struct(mavlink_channel_t chan, const mavlink_pesticides_t* pesticides)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_pesticides_send(chan, pesticides->opened, pesticides->capacity, pesticides->duty);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PESTICIDES, (const char *)pesticides, MAVLINK_MSG_ID_PESTICIDES_MIN_LEN, MAVLINK_MSG_ID_PESTICIDES_LEN, MAVLINK_MSG_ID_PESTICIDES_CRC);
#endif
}

#if MAVLINK_MSG_ID_PESTICIDES_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_pesticides_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t opened, uint8_t capacity, uint8_t duty)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, opened);
    _mav_put_uint8_t(buf, 1, capacity);
    _mav_put_uint8_t(buf, 2, duty);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PESTICIDES, buf, MAVLINK_MSG_ID_PESTICIDES_MIN_LEN, MAVLINK_MSG_ID_PESTICIDES_LEN, MAVLINK_MSG_ID_PESTICIDES_CRC);
#else
    mavlink_pesticides_t *packet = (mavlink_pesticides_t *)msgbuf;
    packet->opened = opened;
    packet->capacity = capacity;
    packet->duty = duty;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PESTICIDES, (const char *)packet, MAVLINK_MSG_ID_PESTICIDES_MIN_LEN, MAVLINK_MSG_ID_PESTICIDES_LEN, MAVLINK_MSG_ID_PESTICIDES_CRC);
#endif
}
#endif

#endif

// MESSAGE PESTICIDES UNPACKING


/**
 * @brief Get field opened from pesticides message
 *
 * @return open action flag
 */
static inline uint8_t mavlink_msg_pesticides_get_opened(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field capacity from pesticides message
 *
 * @return pesticides capacity
 */
static inline uint8_t mavlink_msg_pesticides_get_capacity(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field duty from pesticides message
 *
 * @return action pwm duty
 */
static inline uint8_t mavlink_msg_pesticides_get_duty(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Decode a pesticides message into a struct
 *
 * @param msg The message to decode
 * @param pesticides C-struct to decode the message contents into
 */
static inline void mavlink_msg_pesticides_decode(const mavlink_message_t* msg, mavlink_pesticides_t* pesticides)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    pesticides->opened = mavlink_msg_pesticides_get_opened(msg);
    pesticides->capacity = mavlink_msg_pesticides_get_capacity(msg);
    pesticides->duty = mavlink_msg_pesticides_get_duty(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_PESTICIDES_LEN? msg->len : MAVLINK_MSG_ID_PESTICIDES_LEN;
        memset(pesticides, 0, MAVLINK_MSG_ID_PESTICIDES_LEN);
    memcpy(pesticides, _MAV_PAYLOAD(msg), len);
#endif
}
