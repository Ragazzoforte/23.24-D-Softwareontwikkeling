cmake_minimum_required(VERSION 3.22)

project(stm32cubemx)
add_library(stm32cubemx INTERFACE)

# Enable CMake support for ASM and C languages
enable_language(C ASM)

target_compile_definitions(stm32cubemx INTERFACE 
	USE_HAL_DRIVER 
	STM32F407xx
    $<$<CONFIG:Debug>:DEBUG>
)

target_include_directories(stm32cubemx INTERFACE
    ../../USB_HOST/App
    ../../USB_HOST/Target
    ../../Core/Inc
    ../../Drivers/STM32F4xx_HAL_Driver/Inc
    ../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy
    ../../Middlewares/ST/STM32_USB_Host_Library/Core/Inc
    ../../Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc
    ../../Drivers/CMSIS/Device/ST/STM32F4xx/Include
    ../../Drivers/CMSIS/Include
)

target_sources(stm32cubemx INTERFACE
    ../../Core/Src/user_interface.c
    ../../Core/Src/logic_layer.c
    ../../Core/Src/vga_driver.c
    ../../Core/Src/main.c
    ../../Core/Src/stm32f4xx_it.c
    ../../Core/Src/stm32f4xx_hal_msp.c
    ../../USB_HOST/Target/usbh_conf.c
    ../../USB_HOST/Target/usbh_platform.c
    ../../USB_HOST/App/usb_host.c
    ../../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_hcd.c
    ../../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_usb.c
    ../../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.c
    ../../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.c
    ../../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.c
    ../../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.c
    ../../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.c
    ../../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.c
    ../../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.c
    ../../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.c
    ../../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.c
    ../../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.c
    ../../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.c
    ../../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.c
    ../../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_exti.c
    ../../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2c.c
    ../../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2c_ex.c
    ../../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2s.c
    ../../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2s_ex.c
    ../../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_spi.c
    ../../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.c
    ../../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim_ex.c
    ../../Core/Src/system_stm32f4xx.c
    ../../Middlewares/ST/STM32_USB_Host_Library/Core/Src/usbh_core.c
    ../../Middlewares/ST/STM32_USB_Host_Library/Core/Src/usbh_ctlreq.c
    ../../Middlewares/ST/STM32_USB_Host_Library/Core/Src/usbh_ioreq.c
    ../../Middlewares/ST/STM32_USB_Host_Library/Core/Src/usbh_pipes.c
    ../../Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Src/usbh_cdc.c
    ../../Core/Src/sysmem.c
    ../../Core/Src/syscalls.c
    ../../startup_stm32f407xx.s
)

target_link_directories(stm32cubemx INTERFACE
)

target_link_libraries(stm32cubemx INTERFACE
)

# Validate that STM32CubeMX code is compatible with C standard
if(CMAKE_C_STANDARD LESS 11)
    message(ERROR "Generated code requires C11 or higher")
endif()


