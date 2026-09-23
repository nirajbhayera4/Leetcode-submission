# Write your MySQL query statement below
select Person.firstName,Person.lastname, Address.city,Address.state
from Person
left join Address
on Person.personId=Address.personId;


-- Synced seamlessly with LeetHub Pro
-- Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
-- Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna