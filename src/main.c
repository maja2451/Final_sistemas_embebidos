#include<stdio.h>
#include<string.h>
#include"freertos/FreeRTOS.h"
#include"freertos/task.h"
#include"driver/spi_master.h"

#define PIN_MOSI 23
#define PIN_MISO 19
#define PIN_CLK 18
#define PIN_CS 5

#define MCP4132_SPEED  5000000      

#define MCP4132_MAX_VAL   128
void spi_bus_init(void){
    spi_bus_config_t bus_cfg={
        .mosi_io_num= PIN_MOSI,
        .miso_io_num = PIN_MISO,
        .sclk_io_num = PIN_CLK,
        .quadwp_io_num = -1,
        .quadhd_io_num = -1,
        .max_transfer_sz= 2,
    };
    spi_bus_add_device(SPI2_HOST,&bus_cfg,SPI_DMA_DISABLED);
    if (spi_bus_add_device != ESP_OK) {
        ESP_LOGE("MCP4132", "Error bus SPI: %s", esp_err_to_name(spi_bus_add_device));
        return spi_bus_add_device;
    };


    spi_device_interface_config_t dev_cfg = {
        .mode = 0,

        
        .clock_speed_hz = MCP4132_SPEED,

        .spics_io_num   = PIN_CS,
        .queue_size     = 1,
        .cs_ena_posttrans = 1,
    };

    spi_bus_add_device = spi_bus_add_device(SPI2_HOST, &dev_cfg, & SPI_DMA_DISABLED);
    if (spi_bus_add_device != ESP_OK) {
        ESP_LOGE("MCP4132", "Error add device: %s", esp_err_to_name(spi_bus_add_device));
        return spi_bus_add_device;
    }

    ESP_LOGI("MCP4132", "SPI OK — Mode 0, %d Hz", MCP4132_SPEED);
    return ESP_OK;
}
    



void mpc4132_write_register(void){
    uint16_t tx_data =0xFF;
    uint16_t rx_data[1]={0};

    spi_transaction_t


}

void mpc4132_read_register(void){
    uint16_t=
}

void mpc_4132_set_wiper(uint16_t n){
    if (n > MCP4132_MAX_VAL) n = MCP4132_MAX_VAL;

    uint8_t tx[2] = {
        (MCP4132_ADDR_W0 << 4) | MCP4132_CMD_WRITE, 
        n
    };
    spi_transaction_t t = {
        .length    = 16,        
        .tx_buffer = tx,
        .rx_buffer = NULL,
    };
    return spi_device_transmit(mcp4132_dev, &t);
}


void mcp4132_set_cutoff_frecuency(void){
    
}
void app_main() {

}


