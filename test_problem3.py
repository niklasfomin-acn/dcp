# holds the test that needs to pass for problem3
import pytest
from problem3 import BinaryTreeNode, serialize_helper, deserialize_helper

node = BinaryTreeNode('root', BinaryTreeNode('left', BinaryTreeNode('left.left')), BinaryTreeNode('right'))
assert deserialize_helper(serialize_helper(BinaryTreeNode)).left.left.value == 'left.left' 