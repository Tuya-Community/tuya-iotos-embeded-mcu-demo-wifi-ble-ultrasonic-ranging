# Tuya IoTOS Embedded MCU Demo Wifi Ble Ultrasonic Ranging

[English](./README.md) | [中文](./README_zh.md)

## 简介 

本Demo通过涂鸦智能云平台、涂鸦智能APP、IoTOS Embeded MCU SDK实现超声波测距。

已实现功能包括：

+ 超声波测距



## 快速上手 

### SDK移植

+ [MCU SDK获取](https://developer.tuya.com/cn/docs/iot/device-development/embedded-software-development/mcu-development-access/mcu-access-guide?id=K9hrbv1ub5owo#title-2-产品创建)
+ [MCU SDK移植](https://developer.tuya.com/cn/docs/iot/device-development/embedded-software-development/mcu-development-access/wifi-mcu-sdk-solution/overview-of-migrating-tuyas-mcu-sdk?id=K9hhi0xr5vll9)


### 文件介绍 

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



### Demo入口

入口文件：main.c

重要函数：main()

+ 对mcu的IO口，USART，定时器等进行初始化配置，所有事件在while(1)中轮询判断。




### DP点相关

+ 上报dp点处理: 

| 函数名 | unsigned char mcu_dp_value_update(unsigned char dpid,unsigned long value) |
| ------ | ------------------------------------------------------------ |
| dpid   | DP的ID号                                                     |
| value  | DP数据                                                       |
| Return | SUCCESS: 成功  ERROR: 失败                                   |



### I/O 列表 

| TRIG | ECHO | UASRT1  |
| :--: | :--: | :-----: |
| PC2  | PC3  | PC4 TXD |
|      |      | PC5 RXD |

## 相关文档

涂鸦Demo中心：https://developer.tuya.com/demo/



## 技术支持

您可以通过以下方法获得涂鸦的支持:

- 开发者中心：https://developer.tuya.com
- 帮助中心: https://support.tuya.com/help
- 技术支持工单中心: [https://service.console.tuya.com](https://service.console.tuya.com/) 
