import hashlib
import json
import pytest

dummy_byte = 0xFF
default_n_ae = 0xAE
default_n_sa = 0x5A
default_n_ta = 0x7A
default_st_min = 0x00

custom_n_sa = [pytest.param(na, id='N_Sa = 0x{:02X}'.format(na)) for na in (1, 2)]
custom_n_ta = [pytest.param(na, id='N_Ta = 0x{:02X}'.format(na)) for na in (3, 4)]
custom_n_ae = [pytest.param(na, id='N_Ae = 0x{:02X}'.format(na)) for na in (5, 6)]

single_frame_sizes = [pytest.param(fs, id='SF_DL = {}'.format(fs)) for fs in (1, 2, 6)]
multi_frames_sizes = [pytest.param(fs, id='FF_DL = {}'.format(fs)) for fs in (8, 4095)]

channel_modes = [pytest.param('CANTP_MODE_HALF_DUPLEX', id='half duplex'),
                 pytest.param('CANTP_MODE_FULL_DUPLEX', id='full duplex')]

addressing_formats = [pytest.param('CANTP_EXTENDED', id='extended addressing format'),
                      pytest.param('CANTP_MIXED', id='11 bits mixed addressing format'),
                      pytest.param('CANTP_MIXED29BIT', id='29 bits mixed addressing format'),
                      pytest.param('CANTP_NORMALFIXED', id='fixed addressing format'),
                      pytest.param('CANTP_STANDARD', id='standard addressing format')]

modifiable_parameter_api = [pytest.param('TP_STMIN', id='separation time minimum'),
                            pytest.param('TP_BS', id='block size')]

n_xx_timeouts = [1.0 / 1000000.0 * n for n in (10, 100, 0xFF)]

n_as_timeouts = [pytest.param(t, id='N_As = {}s'.format(t)) for t in n_xx_timeouts]
n_bs_timeouts = [pytest.param(t, id='N_Bs = {}s'.format(t)) for t in n_xx_timeouts]
n_cs_timeouts = [pytest.param(t, id='N_Cs = {}s'.format(t)) for t in n_xx_timeouts]

n_ar_timeouts = [pytest.param(t, id='N_Ar = {}s'.format(t)) for t in n_xx_timeouts]
n_br_timeouts = [pytest.param(t, id='N_Br = {}s'.format(t)) for t in n_xx_timeouts]
n_cr_timeouts = [pytest.param(t, id='N_Cr = {}s'.format(t)) for t in n_xx_timeouts]

addresses = (0, 10, 100, 255)

block_sizes = [pytest.param(bs, id='BS = {}'.format(bs)) for bs in (0, 1, 15, 20)]
wait_for_tx_max = [pytest.param(i, id='WFT max = {}'.format(i)) for i in (1, 2, 3, 4, 5, 6, 7)]


class Config(dict):

    @property
    def get_id(self):
        return hashlib.sha224(json.dumps(self, sort_keys=True, indent=0).encode('utf-8')).hexdigest()[0:8]


class DefaultConfig(Config):
    def __init__(self):
        super(DefaultConfig, self).__init__({
            "configurations": []
        })
