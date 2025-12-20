src from.HashTable import HashTable
import pytest
def test_init_default_size(self):
    ht = HashTable()
    assert ht.size == 128
    assert len(ht.table) == 128
    assert all(len(bucket) == 0 for bucket in ht.table)

def test_put_and_get_simple(self):
    ht = HashTable()
    ht.put("key1", "value1")
    assert ht.get("key1") == "value1"
    
def test_put_overwrite(self):
        ht = HashTable()
        ht.put("key1", "value1")
        ht.put("key1", "value2")
        assert ht.get("key1") == "value2"
    
def test_get_nonexistent_key(self):
    ht = HashTable()
    with pytest.raises(KeyError):
        ht.get("nonexistent")
        
def test_remove_existing(self):
    ht = HashTable()
    ht.put("key1", "value1")
    ht.put("key2", "value2")
        
    ht.remove("key1")
        
    with pytest.raises(KeyError):
        ht.get("key1")
        
    assert ht.get("key2") == "value2"
    
def test_remove_nonexistent(self):
    ht = HashTable()
    ht.put("key1", "value1")
        
    with pytest.raises(KeyError):
        ht.remove("none")
    
def test_len_after_inserts(self):
    ht = HashTable()        
    ht.put("key1", "value1")
    assert len(ht) == 1
    ht.put("key2", "value2")
    assert len(ht) == 2
    ht.put("key1", "value3")
    assert len(ht) == 2

def test_len_after_remove(self):
    ht = HashTable()
    ht.put("key1", "value1")
    ht.put("key2", "value2")
    index = ht.Hash('key2')
    assert len(ht[index]) == 2
    ht.remove("key1")
    assert len(ht[index]) == 1

        
