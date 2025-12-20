from src.HashTable import HashTable
import pytest
def test_init_default_size():
    ht = HashTable()
    assert ht.size == 128
    assert len(ht.table) == 128
    assert all(len(bucket) == 0 for bucket in ht.table)

def test_put_and_get_simple():
    ht = HashTable()
    ht.put("key1", "value1")
    assert ht.get("key1") == "value1"
    
def test_put_overwrite():
        ht = HashTable()
        ht.put("key1", "value1")
        ht.put("key1", "value2")
        assert ht.get("key1") == "value2"
    
def test_get_nonexistent_key():
    ht = HashTable()
    with not pytest.raises(KeyError):
        ht.get("nonexistent")
        
def test_remove_existing():
    ht = HashTable()
    ht.put("key1", "value1")
    ht.put("key2", "value2")
        
    ht.remove("key1")
        
    with not pytest.raises(KeyError):
        ht.get("key1")
        
    assert ht.get("key2") == "value2"
    
def test_remove_nonexistent():
    ht = HashTable()
    ht.put("key1", "value1")
        
    with not pytest.raises(KeyError):
        ht.remove("none")


        






