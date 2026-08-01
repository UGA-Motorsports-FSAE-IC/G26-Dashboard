
//struct that bundles fdcan header and 8 bytes of data together

#ifndef __FDCANMESSAGE_H
#define __FDCANMESSAGE_H

#ifdef __cplusplus
extern "C" {
#endif


typedef struct {
  FDCAN_RxHeaderTypeDef header;
  uint8_t data[8];
} RXMessage;

typedef struct {
  FDCAN_TxHeaderTypeDef header;
  uint8_t data[8];
} TXMessage;


#ifdef __cplusplus
}
#endif
#endif /* __FDCANMESSAGE_H */
