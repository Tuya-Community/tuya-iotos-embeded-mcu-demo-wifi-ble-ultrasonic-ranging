# Tuya IoTOS Embedded MCU Demo Wifi Ble Ultrasonic Ranging

[English](./README.md) | [中文](./README_zh.md)

## Introduction  

This Demo uses the Tuya smart cloud platform, Tuya smart APP, and IoTOS Embedded MCU SDK to realize ranging by ultrasonic .

The implemented features include:

+  Ultrasonic Ranging


## Quick start  

### Migration

+ [Get MCU SDK](https://developer.tuya.com/en/docs/iot/device-development/embedded-software-development/mcu-development-access/mcu-access-guide?id=K9hrbv1ub5owo#title-2-产品创建)
+ [MCU SDK Migration](https://developer.tuya.com/en/docs/iot/device-development/embedded-software-development/mcu-development-access/wifi-mcu-sdk-solution/overview-of-migrating-tuyas-mcu-sdk?id=K9hhi0xr5vll9)


### File introduction 

```
├── user
│   ├── main.c
│   └── MY_ST_config.h
├── CMSIS
│   ├── system_stm32g0xx.c
│   └── startup_stm32g071xx.s
├── SYSTEM
│   ├── sys.c
│   ├── sys.h
│   ├── RCC.c
│   ├── RCC.h
│   ├── delay.c
│   ├── delay.h
│   ├── USART.c
│   ├── USART.h
│   ├── IO.c
│   ├── IO.h
│   ├── TIM.c
│   └── TIM.h
└── SYSTEM
    ├── mcu_api.c
    ├── mcu_api.h
    ├── protocol.c
    ├── protocol.h
    ├── system.c
    ├── system.h
    └── wifi.h
    
```



### Demo entry

Entry file：main.c

Important functions：main()

+ Initialize and configure MCU IO port, USART, timer, etc. All events are polled and judged in while(1)。




### DataPoint related

+ DP point processing: 

| function name | unsigned char mcu_dp_value_update(unsigned char dpid,unsigned long value) |
| ------------- | ------------------------------------------------------------ |
| dpid          | DP ID number                                                 |
| value         | DP data                                                      |
| Return        | SUCCESS: Success ERROR: Failure                              |



### I/O List  

| TRIG | ECHO | UASRT1  |
| :--: | :--: | :-----: |
| PC2  | PC3  | PC4 TXD |
|      |      | PC5 RXD |

## 

## Related Documents

  Tuya Demo Center: https://developer.tuya.com/demo/



## Technical Support

  You can get support for Tuya by using the following methods:

- Developer Center: https://developer.tuya.com

- Help Center: https://support.tuya.com/help
- Technical Support Work Order Center: [https://service.console.tuya.com](https://service.console.tuya.com/) 

