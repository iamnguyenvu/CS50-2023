-- Keep a log of any SQL queries you execute as you solve the mystery.
-- All you know is that the theft took place on July 28, 2021 and that it took place on Humphrey Street.
SELECT description FROM crime_scene_reports
WHERE year = 2021 AND month = 7 AND day = 28 AND street = 'Humphrey Street';

SELECT * FROM bakery_security_logs
WHERE month = 7 AND day = 28 AND hour = 10;

SELECT transcript FROM interviews
WHERE transcript LIKE '%bakery%';

-- SELECT * FROM atm_transactions
-- WHERE atm_location LIKE 'Leggett Street'
-- AND month = 7 AND day = 28 AND transaction_type = 'withdraw';

-- SELECT bank_accounts.person_id FROM bank_accounts
-- WHERE account_number IN (SELECT account_number FROM atm_transactions
-- WHERE atm_location LIKE 'Leggett Street'
-- AND month = 7 AND day = 28 AND transaction_type = 'withdraw');

SELECT * FROM people
WHERE id IN (SELECT bank_accounts.person_id FROM bank_accounts
WHERE account_number IN (SELECT account_number FROM atm_transactions
WHERE atm_location LIKE 'Leggett Street'
AND month = 7 AND day = 28 AND transaction_type = 'withdraw'))
AND license_plate IN (SELECT license_plate FROM bakery_security_logs
WHERE month = 7 AND day = 28 AND hour = 10 AND minute <= 20)
AND phone_number IN (SELECT caller FROM phone_calls
WHERE month = 7 AND day = 28 AND duration < 60);

-- SELECT * FROM people
-- WHERE phone_number In ()

-- SELECT * FROM phone_calls
-- WHERE month = 7 AND day = 28 AND duration < 60;

-- SELECT receiver FROM phone_calls
-- WHERE caller IN (SELECT phone_number FROM people
-- WHERE id IN (SELECT bank_accounts.person_id FROM bank_accounts
-- WHERE account_number IN (SELECT account_number FROM atm_transactions
-- WHERE atm_location LIKE 'Leggett Street'
-- AND month = 7 AND day = 28 AND transaction_type = 'withdraw'))
-- AND license_plate IN (SELECT license_plate FROM bakery_security_logs
-- WHERE month = 7 AND day = 28 AND hour = 10 AND minute <= 20)
-- AND phone_number IN (SELECT caller FROM phone_calls
-- WHERE month = 7 AND day = 28 AND duration < 60))
-- AND month = 7 AND day = 28 AND duration < 60;

SELECT * FROM people
WHERE phone_number = (SELECT receiver FROM phone_calls
WHERE caller IN (SELECT phone_number FROM people
WHERE id IN (SELECT bank_accounts.person_id FROM bank_accounts
WHERE account_number IN (SELECT account_number FROM atm_transactions
WHERE atm_location LIKE 'Leggett Street'
AND month = 7 AND day = 28 AND transaction_type = 'withdraw'))
AND license_plate IN (SELECT license_plate FROM bakery_security_logs
WHERE month = 7 AND day = 28 AND hour = 10 AND minute <= 20)
AND phone_number IN (SELECT caller FROM phone_calls
WHERE month = 7 AND day = 28 AND duration < 60))
AND month = 7 AND day = 28 AND duration < 60);

-- SELECT flight_id FROM passengers
-- WHERE passport_number IN (SELECT passport_number FROM people
-- WHERE id IN (SELECT bank_accounts.person_id FROM bank_accounts
-- WHERE account_number IN (SELECT account_number FROM atm_transactions
-- WHERE atm_location LIKE 'Leggett Street'
-- AND month = 7 AND day = 28 AND transaction_type = 'withdraw'))
-- AND license_plate IN (SELECT license_plate FROM bakery_security_logs
-- WHERE month = 7 AND day = 28 AND hour = 10 AND minute <= 20)
-- AND phone_number IN (SELECT caller FROM phone_calls
-- WHERE month = 7 AND day = 28 AND duration < 60));

-- SELECT destination_airport_id FROM flights
-- WHERE id IN (SELECT flight_id FROM passengers
-- WHERE passport_number IN (SELECT passport_number FROM people
-- WHERE id IN (SELECT bank_accounts.person_id FROM bank_accounts
-- WHERE account_number IN (SELECT account_number FROM atm_transactions
-- WHERE atm_location LIKE 'Leggett Street'
-- AND month = 7 AND day = 28 AND transaction_type = 'withdraw'))
-- AND license_plate IN (SELECT license_plate FROM bakery_security_logs
-- WHERE month = 7 AND day = 28 AND hour = 10 AND minute <= 20)
-- AND phone_number IN (SELECT caller FROM phone_calls
-- WHERE month = 7 AND day = 28 AND duration < 60)));

SELECT city FROm airports
WHERE id IN (SELECT destination_airport_id FROM flights
WHERE id IN (SELECT flight_id FROM passengers
WHERE passport_number IN (SELECT passport_number FROM people
WHERE id IN (SELECT bank_accounts.person_id FROM bank_accounts
WHERE account_number IN (SELECT account_number FROM atm_transactions
WHERE atm_location LIKE 'Leggett Street'
AND month = 7 AND day = 28 AND transaction_type = 'withdraw'))
AND license_plate IN (SELECT license_plate FROM bakery_security_logs
WHERE month = 7 AND day = 28 AND hour = 10 AND minute <= 20)
AND phone_number IN (SELECT caller FROM phone_calls
WHERE month = 7 AND day = 28 AND duration < 60))));
