from twttr import shorten


def main():
    test_lower()
    test_upper()
    test_number()
    test_punctuation()
    test_uppercase()


def test_lower():
    for i in ["a", "e", "i", "o", "u"]:
        assert shorten(i) == ""


def test_upper():
    for j in ["A", "E", "I", "O", "U"]:
        assert shorten(j) == ""


def test_number():
    for k in range(10):
        assert shorten(str(k)) == f"{k}"


def test_punctuation():
    assert shorten(";") == ";"


def test_uppercase():
    assert shorten("s") != "S"


if __name__ == "__main__":
    main()
