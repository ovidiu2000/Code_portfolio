from plates import is_valid




def test_two_letters():
    assert is_valid("Aa") == True


def test_char_num():
    assert is_valid("AAAAAAA") == False


def test_zero():
    assert is_valid("0AA") == False


def test_notalpha():
    assert is_valid("AAA,") == False


def test_num():
    assert is_valid("AA00") == False

def test_alpha():
    assert is_valid("AA0A2P") == False

