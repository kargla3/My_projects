import rclpy
from rclpy.node import Node
from sensor_msgs.msg import LaserScan
import serial
import math

class SerialRviz(Node):
    def __init__(self):
        super().__init__('serial_rviz')
        self.declare_parameter('port', '/dev/ttyUSB0')
        self.declare_parameter('baudrate', 921600)
        self.publisher_ = self.create_publisher(LaserScan, 'scan', 10)
        self.data = ""

        timer_period = 0.1  # sekundy
        self.angle_min = -math.pi  # -90 stopni
        self.angle_max = math.pi   # 90 stopni
        self.angle_increment = math.pi / 180  # 1 stopień
        self.range_min = 0.1  # metry
        self.range_max = 8.0  # metry

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
            self.publish_data(data)
            self.get_logger().info(f'Received: {data}')

    def publish_data(self, data):
        msg = LaserScan()
        msg.ranges = [float(x) / 100.0 for x in data.split(' ')]
        msg.header.frame_id = 'laser_frame'
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.angle_min = self.angle_min 
        msg.angle_max = self.angle_max
        msg.angle_increment = 2 * math.pi / len(msg.ranges)
        msg.range_min = self.range_min
        msg.range_max = self.range_max
        msg.ranges.reverse()

        self.publisher_.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    node = SerialRviz()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()