from fuel import convert, gauge
import pytest


def test_convert_fraction():
    assert convert("3/4") == 75


def test_convert_zero_division():
    with pytest.raises(ZeroDivisionError):
        convert("4/0")


def test_convert_value_error():
    with pytest.raises(ValueError):
        convert("5/4")


def test_gauge_e():
    assert gauge(1) == "E"


def test_gauge_f():
    assert gauge(99) == "F"


def test_gauge_percent():
    assert gauge(75) == "75%"
