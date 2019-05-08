# objectpool
A pool for Object that aims to reduce operations of allocation and deallocation on memory

### Description
It's designed for class or struct, not for linkin types, as constructor and destructor are called implicitly when getting a new object pointer.

A relatively large memory block is allocated when the ObjectPool object is created. Every object being allocated will be created on this memory block.

### Features
Use std::shared_ptr to control the lifetime of objects. When reference count of std::shared_ptr reduces to 1, it indicated that the memory block that is occupied be the object could be recycled. And destructor of the object is called implicitly.

By default, there are 32 objects created initially. User could customize this configuration by passing a number as the two paramter of macro OBJPOOL_DECL, such as OBJPOOL_DECL(ObjectPooltes, 64).

There implemente several Construct function with different amount number of parameter. It supports five parameters at most.

### How to use
It's easy to use. Users could find the usage example in folder `test`.

### Notes
As the constructor without any parameters is called, so a constructor without any parameters must be implemented in the Class which trys to use ObjectPool

### Future plans
Now, it's using std::mutex to maintain concurrency, it may have bad performance in some situations. So I'm considering to use some high tech to replace std::mutex. Maybe sometimes ^^.
