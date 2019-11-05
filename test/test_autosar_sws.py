#!/usr/bin/env python
# -*- coding: utf-8 -*-

from unittest.mock import ANY

from . import *


def test_sws_00138():
    """
    The initialization function of this module shall always have a pointer as a parameter, even though for Variant PC no
    configuration set shall be given. Instead a NULL pointer shall be passed to the initialization function.
    """

    handle = IcuTest(DefaultConfig(), initialize=True)
    handle.lib.Icu_Init(handle.ffi.NULL)
    handle.det_report_error.assert_not_called()
    handle.det_report_runtime_error.assert_not_called()
    handle.det_report_transient_fault.assert_not_called()


@pytest.mark.parametrize('code_name, value', [pytest.param('ICU_E_PARAM_POINTER', 0x0A),
                                              pytest.param('ICU_E_PARAM_CHANNEL', 0x0B),
                                              pytest.param('ICU_E_PARAM_ACTIVATION', 0x0C),
                                              pytest.param('ICU_E_INIT_FAILED', 0x0D),
                                              pytest.param('ICU_E_PARAM_BUFFER_SIZE', 0x0E),
                                              pytest.param('ICU_E_PARAM_MODE', 0x0F),
                                              pytest.param('ICU_E_UNINIT', 0x14),
                                              pytest.param('ICU_E_BUSY_OPERATION', 0x16),
                                              pytest.param('ICU_E_ALREADY_INITIALIZED', 0x17),
                                              pytest.param('ICU_E_PARAM_NOTIFY_INTERVAL', 0x18),
                                              pytest.param('ICU_E_PARAM_VINFO', 0x19)])
def test_sws_00382(code_name, value):
    """
    Development Error Types.
    """

    handle = IcuTest(DefaultConfig(), initialize=False)
    assert handle.define(code_name) == value
