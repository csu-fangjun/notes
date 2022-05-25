TODOs
=====

``asyncio.to_thread()`` runs the function in an executor, where the default
executor is a threadpool executor, which invokes ``loop.run_in_executor()`` indirectly.

How to set the executor of a loop?  Maybe something related to `set_default_executor`?

If we want to schedule a callback to run in the loop from the C++ code, we can use
`loop.call_soon_safe()` method.


