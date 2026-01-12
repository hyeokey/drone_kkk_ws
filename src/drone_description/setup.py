from setuptools import setup
import os
from glob import glob

package_name = 'drone_description'

setup(
    name=package_name,
    version='0.0.0',

    # 파이썬 패키지 아님 → 비워둠
    packages=[],

    data_files=[
        # ament index
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),

        # package.xml
        ('share/' + package_name, ['package.xml']),

        # launch 파일
        (os.path.join('share', package_name, 'launch'),
            glob('launch/*.launch.py')),

        # urdf / xacro 파일
        (os.path.join('share', package_name, 'urdf'),
            glob('urdf/*.xacro')),
    ],

    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='dong',
    maintainer_email='dong@example.com',
    description='Drone URDF and TF description',
    license='Apache License 2.0',
    tests_require=['pytest'],
)
