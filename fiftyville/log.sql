-- Keep a log of any SQL queries you execute as you solve the mystery.
--1st Query To get the description of theft
SELECT
  description
FROM
  crime_scene_reports
WHERE
  MONTH = 7
  AND DAY = 28
  AND street = "Humphrey Street";

--2nd query to investigate based on description that theif was in bakery on 28 July and theft took place at 10:15 am
SELECT
  transcript
FROM
  interviews
WHERE
  transcript LIKE "%bakery%"
  AND DAY = 28
  AND MONTH = 7;

-- INVESTIGATING FIRST WITNESS (RUTH) TESTIMONY
--3rd query to investigate the testimony of first witness (Ruth), that theif went into the parking lot of bakery within 10 minute of theft
SELECT
  *
FROM
  bakery_security_logs
WHERE
  DAY = 28
  AND MONTH = 7
  AND HOUR = 10
  AND MINUTE BETWEEN 15 AND 25;

--4th query to get the names, license_plate and activity of people who exited parking lot within the timeline of theft described by first witness
SELECT
  name,
  people.license_plate,
  activity
FROM
  bakery_security_logs
  JOIN people ON people.license_plate = bakery_security_logs.license_plate
WHERE
  DAY = 28
  AND MONTH = 7
  AND HOUR = 10
  AND MINUTE BETWEEN 15 AND 25;

--First list of suspects
--+---------+---------------+----------+
--|  name   | license_plate | activity |
--+---------+---------------+----------+
--| Vanessa | 5P2BI95       | exit     |
--| Bruce   | 94KL13X       | exit     |
--| Barry   | 6P58WS2       | exit     |
--| Luca    | 4328GD8       | exit     |
--| Sofia   | G412CB7       | exit     |
--| Iman    | L93JTIZ       | exit     |
--| Diana   | 322W7JE       | exit     |
--| Kelsey  | 0NTHK55       | exit     |
--+---------+---------------+----------+
--NOW INVESTIGATING SECOND WITNESS (Eugene) TESTIMONY
--5th query to check the ATM logs of ATM on legget street, specifically logs of withdrawal and get the account number and id of user
SELECT
  id,
  account_number
FROM
  atm_transactions
WHERE
  atm_location = "Leggett Street"
  AND DAY = 28
  AND MONTH = 7
  AND transaction_type = "withdraw";

--6th query to join the tables and get the names corresponding to the account numbers that used atm at day of theft and get the names of
--peoples who used atm at the time of theft
SELECT
  name
FROM
  people
  JOIN bank_accounts ON people.id = bank_accounts.person_id
  JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
WHERE
  DAY = 28
  AND MONTH = 7
  AND transaction_type = "withdraw"
  AND atm_location = "Leggett Street";

--2ND List of suspects
--+---------+
--|  name   |
--+---------+
--| Bruce   |
--| Diana   |
--| Brooke  |
--| Kenny   |
--| Iman    |
--| Luca    |
--| Taylor  |
--| Benista |
--Suspects Remaining:
--1. Bruce
--2. Luca
--3. Iman
--4. Diana
--NOW INVESTIGATING THIRD WITNESS (Raymond) TESTIMONY
--7th query to get the names of people who made phone calls and call duration was less than minute on the day of theft
SELECT DISTINCT
  name
FROM
  people
  JOIN phone_calls ON phone_calls.caller = people.phone_number
WHERE
  duration < 60
  AND DAY = 28
  AND MONTH = 7;

--+---------+
--|  name   |
--+---------+
--| Sofia   |
--| Kelsey  |
--| Bruce   |
--| Taylor  |
--| Diana   |
--| Carina  |
--| Kenny   |
--| Benista |
--Suspects Remaining:
--1. Bruce
--3. Diana
--8th query to get the earliest flight on which theif got out of fiftyville
SELECT
  flights.id
FROM
  flights
  JOIN airports ON flights.origin_airport_id = airports.id
WHERE
  airports.id = 8
  AND DAY = 29
  AND MONTH = 7
ORDER BY
  HOUR asc
LIMIT
  1;

--9th query to get the passengers on flight using flight id
SELECT
  passport_number
FROM
  passengers
  JOIN flights ON passengers.flight_id = flights.id
WHERE
  MONTH = 7
  AND DAY = 29
  AND flights.id = 36;

--10th query to get the names of people using passport_number we got above
SELECT DISTINCT
  name
FROM
  people
  JOIN passengers ON people.passport_number = passengers.passport_number
WHERE
  passengers.flight_id = 36;

--+--------+
--|  name  |
--+--------+
--| Doris  |
--| Sofia  |
--| Bruce  |
--| Edward |
--| Kelsey |
--| Taylor |
--| Kenny  |
--| Luca   |
--+--------+
--Suspects Remaining:
--1. Bruce
--Theif is Bruce
--getting name of bruce using passport_number
SELECT
  name
FROM
  people
WHERE
  passport_number = 5773159633;

--+-------+
--| name  |
--+-------+
--| Bruce |
--+-------+
--11th query to get the accompliance of Bruce using phone number of Bruce
SELECT
  receiver
FROM
  phone_calls
  JOIN people ON phone_calls.caller = people.phone_number
WHERE
  duration < 60
  AND DAY = 28
  AND MONTH = 7
  AND caller = "(367) 555-5533";

--+----------------+
--|    receiver    |
--+----------------+
--| (375) 555-8161 |
--+----------------+
SELECT
  name
FROM
  people
WHERE
  phone_number = "(375) 555-8161";

--+-------+
--| name  |
--+-------+
--| Robin |
--+-------+
--Finding the destination where theif escaped to using destination_airport_id from flight
SELECT
  city
FROM
  airports
  JOIN flights ON airports.id = flights.id
WHERE
  flights.id = 4;

--+---------------+
--|     city      |
--+---------------+
--| New York City |
--+---------------+