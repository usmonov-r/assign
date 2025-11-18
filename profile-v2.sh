#!/bin/bash

# Constants for validation
ID_PATTERN="^[0-9]{8}$"
NAME_PATTERN="^[a-zA-Z ]+$"

# Function to show usage
usage() {
    echo "Usage: $0 <name> <student_id>"
    echo "Example: $0 \"John Doe\" 20230001"
    exit 1
}

# Check argument count
if [ $# -ne 2 ]; then
    echo "Error: Invalid number of arguments."
    usage
fi

NAME="$1"
STUDENT_ID="$2"

# Validate Name (Letters and spaces only)
if [[ ! "$NAME" =~ $NAME_PATTERN ]]; then
    echo "Error: Name must only contain letters and spaces."
    exit 1
fi

# Validate ID (Must be exactly 8 digits)
if [[ ! "$STUDENT_ID" =~ $ID_PATTERN ]]; then
    echo "Error: Student ID must be exactly 8 digits."
    exit 1
fi

# Generate Timestamp
TIMESTAMP=$(date "+%Y-%m-%d %H:%M:%S")

echo "-----------------------------"
echo "Profile Verified: $TIMESTAMP"
echo "Name:       $NAME"
echo "Student ID: $STUDENT_ID"
echo "-----------------------------"
