import hashlib
import json

num_of_hw_channel = 0x06


class Config(dict):

    @property
    def get_id(self):
        return hashlib.sha224(json.dumps(self, sort_keys=True, indent=0).encode('utf-8')).hexdigest()[0:8]


class DefaultConfig(Config):
    def __init__(self):
        default_channel = {
            'channel_id': 0,
            'prescaler': 0,
            'activation_type': 'ICU_RISING_EDGE',
            'measurement_mode': 'ICU_MODE_EDGE_COUNTER',
            'wakeup_capable': True,
            'notification_function': None
        }
        super(DefaultConfig, self).__init__({
            'channels': [default_channel] * num_of_hw_channel
        })
