from bank import value


def test_hello():
    assert value("hello") == 0


def test_h():
    assert value("h") == 20


def test_random():
    assert value("random") == 100


def test_case_long():
    assert value("Hl") == 20
