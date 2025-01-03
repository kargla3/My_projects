import rclpy
from rclpy.node import Node
import serial

class SerialRviz(Node):
    def __init__(self):
        super().__init__('serial_rviz')
        self.declare_parameter('port', '/dev/ttyUSB0')
        self.declare_parameter('baudrate', 921600)

        port = self.get_parameter('port').value
        baudrate = self.get_parameter('baudrate').value

        try:
            self.serial = serial.Serial(port, baudrate, timeout=1)
            self.get_logger().info(f'Connected to {port} at {baudrate} baud.')
            self.create_timer(0.1, self.read_data)
        except serial.SerialException as e:
            self.get_logger().error(f'Error opening port: {e}')

    def read_data(self):
        if self.serial.in_waiting > 0:
            data = self.serial.readline().decode('utf-8').strip()
            self.get_logger().info(f'Received: {data}')

def main(args=None):
    rclpy.init(args=args)
    node = SerialRviz()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()