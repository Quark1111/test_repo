from src.HeapSort import heap_sort
import pytest 
@pytest.mark.parametrize(
 ["input", "output"],
    [
        ([4, 3, 2, 0, -1, 4, 3], [-1, 0, 2, 3, 3, 4, 4]),
        ([1, 2, 3, 0, 0, 0], [0, 0, 0, 1, 2, 3]),
        ([5, 4, -9, 13, 45, 1, 480, -14, -5, 1],[-14, -9, -5, 1, 1, 4, 5, 13, 45, 480],),
        ([64, 34, 25, 12, 22, 11, 90], [11, 12, 22, 25, 34, 64, 90]),
        ([0], [0]),
        ([-8, -3, -5, -10, -11], [-11, -10, -8, -5, -3]),
        ([1, 2, 3], [1, 2, 3]),
        ([3, 2, 1], [1, 2, 3])
     ],
)

def test_basic(input, output):
    assert heap_sort(input) == output

def test_empty():
    assert heap_sort([]) == []

def test_negative():
    assert heap_sort([32, 11, 12, 14, -10, 0, 9, 0, 0, 0, -7, 112, 3, -110]) == [-110, -10, -7, 0, 0, 0, 0, 3, 9, 11,  , 14, 32, 112]
