import smbus

#some MPU6050 Registers and their Address
PWR_MGMT_1   = 0x6B
SMPLRT_DIV   = 0x19
CONFIG       = 0x1A
GYRO_CONFIG  = 0x1B
INT_ENABLE   = 0x38
ACCEL_XOUT_H = 0x3B
ACCEL_YOUT_H = 0x3D
ACCEL_ZOUT_H = 0x3F
GYRO_XOUT_H  = 0x43
GYRO_YOUT_H  = 0x45
GYRO_ZOUT_H  = 0x47

Device_Address = 0x68

acc_bias = [28.00, -23.62, -180.25]
gyro_bias = [-631.83, 26.18, -224.23]

class ImuReader:

    def __init__(self):
        # bus initialization
        self.bus = smbus.SMBus(1)

        # write to sample rate register
        self.bus.write_byte_data(Device_Address, SMPLRT_DIV, 7)
        # Write to power management register
        self.bus.write_byte_data(Device_Address, PWR_MGMT_1, 1)
        # Write to Configuration register
        self.bus.write_byte_data(Device_Address, CONFIG, 0)
        # Write to Gyro configuration register
        self.bus.write_byte_data(Device_Address, GYRO_CONFIG, 24)
        # Write to interrupt enable register
        self.bus.write_byte_data(Device_Address, INT_ENABLE, 1)

    def read_raw_data(self, addr):
        #Accelero and Gyro value are 16-bit
        high = self.bus.read_byte_data(Device_Address, addr)
        low = self.bus.read_byte_data(Device_Address, addr + 1)

        #concatenate higher and lower value
        value = ((high << 8) | low)
        
        #to get signed value from mpu6050
        if(value > 32768):
            value = value - 65536
        return value

    def read(self):
        # Read Accelerometer raw value
        acc_x = (self.read_raw_data(ACCEL_XOUT_H) - acc_bias[0]) / 16384.0 * 9.807
        acc_y = (self.read_raw_data(ACCEL_YOUT_H) - acc_bias[1]) / 16384.0 * 9.807
        acc_z = (self.read_raw_data(ACCEL_ZOUT_H) - acc_bias[2]) / 16384.0 * 9.807
        
        # Read Gyroscope raw value
        gyro_x = (self.read_raw_data(GYRO_XOUT_H) - gyro_bias[0]) / 131.0 * (3.1415926 / 180.0)
        gyro_y = (self.read_raw_data(GYRO_YOUT_H) - gyro_bias[1]) / 131.0 * (3.1415926 / 180.0)
        gyro_z = (self.read_raw_data(GYRO_ZOUT_H) - gyro_bias[2]) / 131.0 * (3.1415926 / 180.0)

        return (acc_x, acc_y, acc_z), (gyro_x, gyro_y, gyro_z)


