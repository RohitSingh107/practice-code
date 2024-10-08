import asyncio
from aiologger import Logger
from aiologger.handlers.files import AsyncFileHandler
import traceback
from functools import wraps

# # Create asynchronous loggers for each level
# info_logger = Logger.with_default_handlers(name='info_logger')
# info_handler = AsyncFileHandler('info.log')
# info_logger.add_handler(info_handler)
#
# debug_logger = Logger.with_default_handlers(name='debug_logger')
# debug_handler = AsyncFileHandler('debug.log')
# debug_logger.add_handler(debug_handler)
#
# error_logger = Logger.with_default_handlers(name='error_logger')
# error_handler = AsyncFileHandler('error.log')
# error_logger.add_handler(error_handler)




class LoggerSingleton:
    _instance = None
    
    def __new__(cls):
        if cls._instance is None:
            cls._instance = super(LoggerSingleton, cls).__new__(cls)
            cls._instance._initialize_loggers()
        return cls._instance

    def _initialize_loggers(self):
        # Initialize loggers only once
        self._info_logger = None
        self._debug_logger = None
        self._error_logger = None
    
    def get_info_logger(self):
        if self._info_logger is None:
            self._info_logger = Logger.with_default_handlers(name='info_logger')
            info_handler = AsyncFileHandler('info.log')
            self._info_logger.add_handler(info_handler)
        return self._info_logger

    def get_debug_logger(self):
        if self._debug_logger is None:
            self._debug_logger = Logger.with_default_handlers(name='debug_logger')
            debug_handler = AsyncFileHandler('debug.log')
            self._debug_logger.add_handler(debug_handler)
        return self._debug_logger

    def get_error_logger(self):
        if self._error_logger is None:
            self._error_logger = Logger.with_default_handlers(name='error_logger')
            error_handler = AsyncFileHandler('error.log')
            self._error_logger.add_handler(error_handler)
        return self._error_logger

# Usage
logger_singleton = LoggerSingleton()
info_logger = logger_singleton.get_info_logger()
debug_logger = logger_singleton.get_debug_logger()
error_logger = logger_singleton.get_error_logger()

# Decorator that takes a return_value argument
def log_errors(return_value=None):
    def decorator(async_func):
        @wraps(async_func)
        async def wrapper(*args, **kwargs):
            try:
                return await async_func(*args, **kwargs)
            except Exception as e:
                # Log the full traceback, and make sure to await it
                error_message = f"Error in {async_func.__name__}: {e}\n{traceback.format_exc()}"
                await error_logger.error(error_message)
                print(f"Error logged. Returning fallback value: {return_value}")
                return return_value  # Return the fallback value
        return wrapper
    return decorator

# Example of using the decorator with a fallback return value
@log_errors(return_value="Fallback value due to exception")
async def f():
    await info_logger.info('This is an info message')
    return 110 / 0  # This will cause a ZeroDivisionError

async def main():
    await debug_logger.debug('This is a debug message')
    result = await f()
    print(f"Result of f(): {result}")
    
    # Properly shutdown the loggers at the end to ensure all logs are written
    await info_logger.shutdown()
    await debug_logger.shutdown()
    await error_logger.shutdown()

# Run the asynchronous main function
asyncio.run(main())
