from setuptools import setup, find_packages

package_name = 'decision_node'

setup(
    name=package_name,
    version='0.0.1',
    packages=find_packages(),
    data_files=[
        ('share/ament_index/resource_index/packages', ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='dong',
    maintainer_email='you@todo.todo',
    description='Decision/FSM for drone missions',
    license='Apache-2.0',
    entry_points={
        'console_scripts': [
            'waypoint_fsm = decision_node.mission_waypoint.waypoint_fsm:main',
        ],
    },
)
