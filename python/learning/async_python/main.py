
import asyncio
import time

from icecream import ic

ic.configureOutput(includeContext=True)


shared_resource = 0
lock = asyncio.Lock()

async def fetch_data(delay, id):
    ic(f"Fetching data id {id}...")
    await asyncio.sleep(delay)
    ic("Data Fetched, id: ", id)
    return {"data" : "Some data", "id" : id}


async def set_future_result(future, value):
    await asyncio.sleep(2) # Doing something 

    future.set_result(value)
    ic(f"Set thr future's result to {value}")

    await asyncio.sleep(10)
    ic("Doing other tasks but it does not matter as future value is already set")
    return "Value after function finished (does't matter in future)"


async def modify_shared_resource():
    global shared_resource

    async with lock: # acquire
        ic(f"Resource beofre modification: {shared_resource}")
        shared_resource += 1

        await asyncio.sleep(1) # Some IO operation

        ic(f"Resource after modification: {shared_resource}")

    # release

async def access_resource(semaphore, resource_id):
    async with semaphore:
        ic(f"Accessing Resource: {resource_id}")
        await asyncio.sleep(1) # Some io work
        ic(f"Releasing Resource: {resource_id}")



async def waiter(event):
    ic("waiting for the event to set")
    await event.wait()
    ic("event has been set, coninuing execution")

async def setter(event):
    await asyncio.sleep(2) # Some IO work
    event.set()
    ic("event has been set!")


async def main():

    ic("Start of main couritine")

    # c = fetch_data(2)
    # ic("Courutune created but function not called")
    # r = await c
    #
    # ic(f"Received result: {r}")

    # c1 = fetch_data(2, 1)
    # c2 = fetch_data(2, 2)
    #
    # r1 = await c1
    # ic(f"Received result: {c1}")
    # 
    # r2 = await c2
    # ic(f"Received result: {r2}")

    # t1 = asyncio.create_task(fetch_data(3,1))
    # t2 = asyncio.create_task(fetch_data(2,2))
    # ic("task alread scheduled but not called")
    # t3 = asyncio.create_task(fetch_data(2,3))
    #
    # r1 = await t1
    # r2 = await t2
    # r3 = await t3
    #
    # ic("Result: ", r1, r2, r3)


    # results = await asyncio.gather(fetch_data(3,1), fetch_data(2,2), fetch_data(2,3), fetch_data(4,4))
    #
    # ic(results)

    tasks = []
    async with asyncio.TaskGroup() as tg:
        for i, sleep_time in enumerate([3,2,2,4], start=1):
            t = tg.create_task(fetch_data(sleep_time, i))
            tasks.append(t) # if result required

    # ic(tasks)
    results = [t.result() for t in tasks]
    ic(results)

    

    loop = asyncio.get_running_loop()
    future = loop.create_future()

    asyncio.create_task(set_future_result(future, "Future is ready"))

    result = await future
    ic(result)


    
    # LOCK
    await asyncio.gather(*(modify_shared_resource() for _ in range(5)))


    # Semaphore
    semaphore = asyncio.Semaphore(2)
    await asyncio.gather(*(access_resource(semaphore, i) for  i in range(5)))




    # Event
    event = asyncio.Event()
    await asyncio.gather(waiter(event), setter(event))


    ic("End of main couritine")


asyncio.run(main())
